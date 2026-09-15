PORTNAME=	vite-plus
DISTVERSIONPREFIX=v
DISTVERSION=	0.2.9
PORTREVISION=	2
CATEGORIES=	devel

# rolldown is a PATH dependency (~48 `path = "./rolldown/crates/*"` entries in
# the root Cargo.toml) that upstream syncs into the tree at dev time via
# `just init` (packages/tools sync-remote). The release tarball does NOT ship
# it, so fetch the pinned rolldown tree separately and place it at
# ${WRKSRC}/rolldown (see post-extract). Pinned hash is
# packages/tools/.upstream-versions.json.
# GitHub serves the pinned tree at .../archive/<SHA>.tar.gz (the top-level
# dir inside is "rolldown-<SHA>/").
ROLLDOWN_HASH=	52dbd194ea6b6d4320706caa5f2db14b1034adaf
MASTER_SITES+=	https://github.com/rolldown/rolldown/archive/:rolldown_src
DISTFILES+=	${ROLLDOWN_HASH}.tar.gz:rolldown_src

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Vite Plus the Unified Toolchain for the Web
WWW=		https://github.com/voidzero-dev/vite-plus \
		https://viteplus.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	voidzero-dev

# The root Cargo.toml is a VIRTUAL workspace (no [package]) and the `vp` binary
# lives in crates/vp_global_cli, so the default CARGO_INSTALL_PATH='.' would
# fail. Name the binary crate explicitly.
CARGO_INSTALL_PATH=crates/vp_global_cli

# fspy embeds the fspy_preload_unix cdylib at compile time through cargo's
# UNSTABLE bindeps (artifact! / CARGO_CDYLIB_FILE_*), and its proc-macro crate
# uses #![feature(proc_macro_tracked_env)] + proc_macro::tracked — both
# nightly-gated. The ports cargo framework rewrites ${WRKSRC}/.cargo/config.toml
# (it drops `[unstable] bindeps = true` and `[env] WORKSPACE_DIR = "rolldown"`),
# so re-provide both in the build env:
#   - RUSTC_BOOTSTRAP=1 unlocks the feature/`-Z` gates on the STABLE toolchain
#     (no lang/rust-nightly required).
#   - CARGO_UNSTABLE_BINDEPS=true enables bindeps via env (rather than the
#     `-Z bindeps` build arg) so it also survives the framework's `cargo update`
#     configure step, which needs the `artifact = "cdylib"` dep syntax.
#   - WORKSPACE_DIR=rolldown is read by the rolldown_workspace crate via env!
#   - RELEASE_BUILD=1 build binding libraries
CARGO_ENV+=	RUSTC_BOOTSTRAP=1
CARGO_ENV+=	CARGO_UNSTABLE_BINDEPS=true
CARGO_ENV+=	WORKSPACE_DIR=rolldown
CARGO_ENV+=	RELEASE_BUILD=1

PLIST_FILES=	bin/vp \
		lib/${PORTNAME}/libvite_plus_cli.so \
		lib/${PORTNAME}/librolldown_binding.so \
		lib/${PORTNAME}/libvp_pm_cli_macros.so

VITE_RELEASE_LIBS=	libvite_plus_cli.so \
			librolldown_binding.so \
			libvp_pm_cli_macros.so


# The framework auto-extracts every DISTFILE into ${WRKDIR}; move the rolldown
# tree to ${WRKSRC}/rolldown so the ./rolldown/crates/* path deps resolve.
post-extract:
	@${MV} ${WRKDIR}/rolldown-${ROLLDOWN_HASH} ${WRKSRC}/rolldown

# The framework auto-applies ${PATCHDIR}/patch-* to ${WRKSRC} during do-patch.
# The vp_js_runtime patch (files/patch-vp_js_runtime-freebsd) lives in the main
# source tree and is applied automatically by do-patch.  The fspy patch,
# however, targets the vite-task git-sourced dep, which is extracted to
# ${WRKDIR}/vite-task-<sha>/ and is NOT auto-patched by the cargo framework.
# It is therefore named fspy-freebsd.patch (so do-patch's patch-* glob skips it)
# and applied explicitly here, to the extracted vite-task tree.
# NOTE: no parse-time `.if exists()` here — ${PATCHDIR} is only defined later in
# bsd.port.mk, so the existence check must happen at runtime inside the recipe.
post-patch:
	@(for d in ${WRKDIR}/vite-task-*; do \
	     [ -d "$$d" ] || continue; \
	     if [ -f ${PATCHDIR}/fspy-freebsd.patch ]; then \
	       (cd "$$d" && ${PATCH} -p1 < ${PATCHDIR}/fspy-freebsd.patch); \
	     fi; \
	   done)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for f in ${VITE_RELEASE_LIBS}
	@${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/${f} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
.endfor

# To update Makefile.crates execute: make cargo-crates > Makefile.crates

.include <bsd.port.mk>
