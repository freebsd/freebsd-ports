# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	libimg
PORTVERSION=	1.4.7
CATEGORIES?=	graphics tk
MASTER_SITES=	SF/tkimg/tkimg/${PORTVERSION:R}/tkimg%20${PORTVERSION}
DISTNAME=	Img-Source-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library of image format handlers for Tk4.1 and later

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	auto-accept pkg-sell pkg-mirror dist-sell dist-mirror

BUILD_DEPENDS=	dtplite:devel/tcllib
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

USES=		autoreconf jpeg tk:tea zip
USE_XORG=	x11 xext xft xrender xscrnsaver
OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

# We don't need the bundled libraries:
EXTRACT_AFTER_ARGS=	-x '*/libz/*' -x zlib \
		-x 'config.*' -x Makefile \
		-x '*/compat/*' -x '*/libtiff/*' \
		-x '*/libjpeg/*' -x '*/libpng/*' -a -d ${WRKDIR}
MAKE_ARGS+=	INSTALL_ROOT="${STAGEDIR}"
CONFIGURE_ENV=	WRKDIR="${WRKDIR}"

post-patch:
	${REINPLACE_CMD} -E -e 's,"(zlib|tiff|jpeg|png)tcl.h",<\1.h>,' \
		-e 's,jpeg\.h,jpeglib.h,' ${WRKSRC}/*/*.[ch]
.for d in jpeg png tiff zlib
	${TOUCH} ${WRKDIR}/$dtclConfig.sh
.endfor

pre-configure:
	${CHMOD} +x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.for l in jpeg png tiff
	# Link with -l$l
	${REINPLACE_CMD} -E \
		-e 's,^SHLIB_LD_LIBS[[:space:]]*=[[:space:]]*(.*),SHLIB_LD_LIBS=\1 -l$l,' \
		${WRKSRC}/$l/Makefile
.endfor

test check regression-test: build
	cd ${WRKSRC}/tests && \
	${SETENV} TCLLIBPATH=${WRKSRC:Q} ${WISH} ${WRKSRC}/tests/all

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_DATA} ${WRKSRC}/msgs/*.msg ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_SCRIPT} ${WRKSRC}/demo.tcl ${WRKSRC}/tkv.tcl ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
