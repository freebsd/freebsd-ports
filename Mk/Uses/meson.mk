# $FreeBSD$
#
# Provide support for Meson based projects
#
# Feature:		meson
# Usage:		USES=meson
#
# The following files are bundled in source tar files.
# meson.build		- Instructions for meson like autoconf configure,
#			there is no changeable parts in the file.
# meson_options.txt	- All the options meson understands
#
# Variables for ports:
# MESON_ARGS		- Arguments passed to meson
#			format: -Denable_foo=true
# MESON_BUILD_DIR	- Path to the build directory
#			Default: ${WRKSRC}/_build
#
# MAINTAINER: gnome@FreeBSD.org

.if !defined(_INCLUDE_USES_MESON_MK)
_INCLUDE_USES_MESON_MK=	yes

# Sanity check
.if !empty(meson_ARGS)
IGNORE=	Incorrect 'USES+= meson:${meson_ARGS}'. meson takes no arguments
.endif

BUILD_DEPENDS+=		meson:devel/meson

# meson uses ninja
.include "${USESDIR}/ninja.mk"

# meson might have issues with non-unicode locales
USE_LOCALE?=	en_US.UTF-8

CONFIGURE_ARGS+=	--prefix ${PREFIX} \
			--mandir man

# meson has it own strip mechanic
INSTALL_TARGET=		install

# should we have strip separate from WITH_DEBUG?
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--buildtype debug
.else
CONFIGURE_ARGS+=	--buildtype release \
			--strip
.endif

HAS_CONFIGURE=		yes
CONFIGURE_CMD=		meson
# Pull in manual set settings and from options
CONFIGURE_ARGS+=	${MESON_ARGS}

BUILD_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}

INSTALL_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}

TEST_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}
TEST_TARGET=		test

MESON_BUILD_DIR?=	_build

# Add meson build dir at the end.
CONFIGURE_ARGS+=	${MESON_BUILD_DIR}

# Add this workaround copied from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=218067
# to make sure meson installs the pkg-config in the current correct place
.if !target(fixup-lib-pkgconfig)
_USES_install+= 601:fixup-lib-pkgconfig
fixup-lib-pkgconfig:
	@if [ -d ${STAGEDIR}${PREFIX}/lib/pkgconfig ]; then \
		if [ -z "$$(${FIND} ${STAGEDIR}${PREFIX}/lib/pkgconfig -maxdepth 0 -empty)" ]; then \
			${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig; \
			${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* ${STAGEDIR}${PREFIX}/libdata/pkgconfig; \
		fi; \
		${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig; \
	fi
.endif

.endif #!defined(_INCLUDE_USES_MESON_MK)
