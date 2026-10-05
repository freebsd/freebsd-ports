#!/usr/bin/env python3
"""Make OpenCode's bundled @opentui/core work on FreeBSD, self-contained.

Steps:
  1. Patch the bundled @opentui/core JS so the native-asset loader accepts
     `freebsd` and resolves the matching platform package.
  2. Create that platform package (holding the FreeBSD libopentui.so built by
     Zig) so `bun build --compile` embeds the shared object into the binary.

Usage:
  setup-opentui-freebsd.py <opencode-root> <path-to-libopentui.so> <version> <arch>

Where <arch> is "x64" or "arm64" (the Node/Bun arch tag), and
<opencode-root> is the checked-out opencode source tree (the directory
containing node_modules/).
"""
import os
import re
import shutil
import sys

NATIVE_OLD = """var NATIVE_FILE_NAMES = {
  darwin: "libopentui.dylib",
  linux: "libopentui.so",
  win32: "opentui.dll"
};"""

NATIVE_NEW = """var NATIVE_FILE_NAMES = {
  darwin: "libopentui.dylib",
  linux: "libopentui.so",
  win32: "opentui.dll",
  freebsd: "libopentui.so"
};"""

# Inserted immediately before the terminal throw in resolveNativeLibraryPath().
THROW = '  throw new Error(`OpenTUI is not supported on the current platform: ${asset.packageName}`);'
BRANCH = """  if (process.platform === "freebsd") {
    if (process.arch === "x64") {
      return (await import("@opentui/core-freebsd-x64")).default;
    }
    if (process.arch === "arm64") {
      return (await import("@opentui/core-freebsd-arm64")).default;
    }
  }
"""

BUNDLE_FILES = ["chunk-bun-sjw2d9bq.js", "node-assets.js"]

# Upstream disables the native renderer thread on Linux because it is
# unreliable; on FreeBSD it deadlocks (the TUI freezes after the first render),
# so force it off there too.  The bundle keeps the guard and the assignment on
# separate lines, so match across the whitespace between them.
RENDERER_THREAD_RE = re.compile(r'(if \(process\.platform === "linux")\)(\s*config\.useThread = false)')
RENDERER_THREAD_NEW = r'\1 || process.platform === "freebsd")\2'

INDEX_BUN = """const module = await import("./libopentui.so", { with: { type: "file" } })

export default module.default
"""

INDEX_JS = """import { fileURLToPath } from "node:url"

export default fileURLToPath(new URL("./libopentui.so", import.meta.url))
"""

INDEX_DTS = "declare const path: string\nexport default path\n"

PKG_JSON = """{
  "name": "@opentui/core-freebsd-%ARCH%",
  "version": "%VERSION%",
  "description": "Prebuilt freebsd-%ARCH% binaries for @opentui/core",
  "type": "module",
  "main": "index.js",
  "module": "index.js",
  "types": "index.d.ts",
  "exports": {
    ".": {
      "bun": "./index.bun.js",
      "import": "./index.js",
      "types": "./index.d.ts"
    }
  },
  "os": ["freebsd"],
  "cpu": ["%ARCH%"]
}
"""


def find_core(root: str) -> str:
    base = os.path.join(root, "node_modules", ".bun")
    for name in sorted(os.listdir(base)):
        if name.startswith("@opentui+core@0.5.14"):
            core = os.path.join(base, name, "node_modules", "@opentui", "core")
            if os.path.isdir(core):
                return core
    raise SystemExit(f"@opentui/core not found under {base}")


def patch_bundles(core: str) -> None:
    for name in BUNDLE_FILES:
        path = os.path.join(core, name)
        if not os.path.exists(path):
            print(f"  - skip missing {name}")
            continue
        src = open(path, encoding="utf-8").read()
        changed = False
        if 'freebsd: "libopentui.so"' not in src and NATIVE_OLD in src:
            src = src.replace(NATIVE_OLD, NATIVE_NEW, 1)
            changed = True
        if 'process.platform === "freebsd"' not in src and THROW in src:
            src = src.replace(THROW, BRANCH + THROW, 1)
            changed = True
        if changed:
            open(path, "w", encoding="utf-8").write(src)
            print(f"  - patched {name}")

    # Disable the native renderer thread on FreeBSD (see RENDERER_THREAD_RE).
    for name in sorted(os.listdir(core)):
        if not name.endswith(".js"):
            continue
        path = os.path.join(core, name)
        src = open(path, encoding="utf-8").read()
        out, n = RENDERER_THREAD_RE.subn(RENDERER_THREAD_NEW, src)
        if n:
            open(path, "w", encoding="utf-8").write(out)
            print(f"  - disabled renderer thread in {name} ({n})")


def create_platform_package(root: str, lib: str, version: str, arch: str) -> str:
    dest = os.path.join(root, "node_modules", "@opentui", f"core-freebsd-{arch}")
    os.makedirs(dest, exist_ok=True)
    shutil.copyfile(lib, os.path.join(dest, "libopentui.so"))
    open(os.path.join(dest, "index.bun.js"), "w", encoding="utf-8").write(INDEX_BUN)
    open(os.path.join(dest, "index.js"), "w", encoding="utf-8").write(INDEX_JS)
    open(os.path.join(dest, "index.d.ts"), "w", encoding="utf-8").write(INDEX_DTS)
    open(os.path.join(dest, "package.json"), "w", encoding="utf-8").write(
        PKG_JSON.replace("%VERSION%", version).replace("%ARCH%", arch)
    )
    return dest


def main() -> int:
    root = sys.argv[1]
    lib = sys.argv[2]
    version = sys.argv[3] if len(sys.argv) > 3 else "0.5.14"
    arch = sys.argv[4] if len(sys.argv) > 4 else "x64"
    if arch not in ("x64", "arm64"):
        raise SystemExit(f"unsupported arch tag: {arch}")
    core = find_core(root)
    print(f"core: {core}")
    patch_bundles(core)
    dest = create_platform_package(root, lib, version, arch)
    print(f"platform package: {dest}")
    for name in ("index.bun.js", "index.js", "package.json", "libopentui.so"):
        p = os.path.join(dest, name)
        print(f"  {name}: {os.path.getsize(p)} bytes")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
