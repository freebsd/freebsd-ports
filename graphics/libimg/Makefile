# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	libimg
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES?=	graphics tk
MASTER_SITES=	SF/tkimg/tkimg/${PORTVERSION:R}
DISTNAME=	tkimg${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library of image format handlers for Tk4.1 and later

BUILD_DEPENDS=	dtplite:devel/tcllib
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PLIST_SUB+=	SHLIB_NAME="${SHLIB_NAME}" \
		SHLIB_LINK="${SHLIB_LINK}"

WRKSRC=		${WRKDIR}/tkimg${PORTVERSION:R}
USES=		autoreconf jpeg tk:tea tar:bzip2

# We don't need the bundled libraries:
EXTRACT_AFTER_ARGS=	--exclude '*/libz/*' --exclude zlib \
		--exclude 'config.*' --exclude Makefile \
		--exclude '*/compat/*' --exclude '*/libtiff/*' \
		--exclude '*/libjpeg/*' --exclude '*/libpng/*'
MAKE_ARGS+=	INSTALL_ROOT="${STAGEDIR}"
CONFIGURE_ENV=	WRKDIR="${WRKDIR}"

post-patch:
	${REINPLACE_CMD} -E -e 's,"(zlib|tiff|jpeg|png)tcl.h",<\1.h>,' \
		-e 's,jpeg\.h,jpeglib.h,' ${WRKSRC}/*/*.[ch]
.for d in jpeg png tiff zlib
	touch ${WRKDIR}/$dtclConfig.sh
.endfor

post-configure:
	# Do not link with X11 -- none of tkimg code uses X directly
	${REINPLACE_CMD} -E -e 's,-L[^[:space:]]+[[:space:]]+-lX[^[:space:]]*,,g' \
		${WRKSRC}/*/Makefile
.for l in jpeg png tiff
	# Link with -l$l
	${REINPLACE_CMD} -E \
		-e 's,^SHLIB_LD_LIBS[[:space:]]*=[[:space:]]*(.*),SHLIB_LD_LIBS=\1 -l$l,' \
		${WRKSRC}/$l/Makefile
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_DATA} ${WRKSRC}/msgs/*.msg ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_SCRIPT} ${WRKSRC}/demo.tcl ${WRKSRC}/tkv.tcl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
