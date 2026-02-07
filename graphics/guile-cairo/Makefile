PORTNAME=	guile-cairo
DISTVERSION=	1.11.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH
PKGNAMESUFFIX=  -${FLAVOR}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Wrapper for using the Cairo graphics library from Guile
WWW=		https://www.nongnu.org/guile-cairo/

LICENSE=	LGPL3+

USES=		guile:2.2,3.0,flavors,alias \
		autoreconf gettext-tools gmake gnome libtool pkgconfig
guile30_CSTD=   c11
guile22_CSTD=   c99
USE_CSTD=	${${FLAVOR}_CSTD}
USE_GNOME=	cairo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--includedir='$${prefix}/include/guile/${GUILE_VER}' \
		--libdir='$${prefix}/lib/guile/${GUILE_VER}/extensions'

MAKE_JOBS_UNSAFE=yes

INSTALL_TARGET=	install-strip

# Upstream has done almost all of the de-conflicting work, but there is
# no release at this time. Include their work as a patch, which also
# covers the code needed by g-golf.

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-upstream-fixes.patch

INFO=		guile-cairo
INFO_PATH=	${GUILE_INFO_PATH}

post-patch:
	${REINPLACE_CMD} \
		-e '/^objdir=/s:$$(libdir)/:$$(exec_prefix)/lib/:' \
		${WRKSRC}/Makefile.am ${WRKSRC}/cairo/Makefile.am

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}
	${MV} ${STAGEDIR}${PREFIX}/lib/guile/${GUILE_VER}/extensions/pkgconfig/*.pc \
	      ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}/
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/guile/${GUILE_VER}/extensions/pkgconfig

.include <bsd.port.mk>
