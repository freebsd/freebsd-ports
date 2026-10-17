Teach OpenCode's CLI build script about FreeBSD.

Upstream's target list only covers linux, darwin and win32, and its per-target
plugins assume a native @parcel/watcher package and bytecode support, neither of
which exists on FreeBSD:

  * add the freebsd arm64/x64 targets so `--target=opencode-freebsd-<arch>`
    resolves and `Bun.build({ compile: { target: "bun-freebsd-<arch>" } })`
    produces a FreeBSD executable;
  * degrade the parcel-watcher binding to a stub on FreeBSD (there is no
    @parcel/watcher-freebsd-* package); the watcher service already falls back
    to node:fs for file/entries watches and logs "backend not supported" for
    recursive directories;
  * disable bytecode on FreeBSD, where bun does not emit it.

--- packages/cli/script/build.ts.orig
+++ packages/cli/script/build.ts
@@ -48,4 +48,6 @@
   { os: "win32", arch: "arm64" },
   { os: "win32", arch: "x64" },
   { os: "win32", arch: "x64", avx2: false },
+  { os: "freebsd", arch: "arm64" },
+  { os: "freebsd", arch: "x64" },
 ]
@@ -112,8 +114,9 @@
     name: "parcel-watcher-binding",
     setup(build) {
-      build.onLoad({ filter: /filesystem[/\\]watcher-binding\.ts$/ }, () => ({
-        contents: `export default () => require(${JSON.stringify(parcelWatcherPackage)})`,
-        loader: "js",
-      }))
+      build.onLoad({ filter: /filesystem[/\\]watcher-binding\.ts$/ }, () =>
+        item.os === "freebsd"
+          ? { contents: `export default () => { throw new Error("parcel watcher is unavailable on FreeBSD") }`, loader: "js" }
+          : { contents: `export default () => require(${JSON.stringify(parcelWatcherPackage)})`, loader: "js" },
+      )
     },
   }
@@ -129,7 +132,7 @@
     format: "esm",
     minify: true,
-    bytecode: true,
+    bytecode: item.os !== "freebsd",
     sourcemap: Script.channel === "dev" || Script.channel === "local" ? "inline" : "none",
     splitting: true,
     compile: {
