PORTNAME=	libimg
PORTVERSION=	1.4.12
CATEGORIES?=	graphics tk tcl
MASTER_SITES=	SF/tkimg/tkimg/${PORTVERSION:R}/tkimg%20${PORTVERSION}
DISTNAME=	Img-${PORTVERSION}-Source

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

USES=		autoreconf jpeg tk:tea xorg dos2unix

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_XORG=	x11 xext xft xrender xscrnsaver
OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes
WRKSRC=		${WRKDIR}/Img-${PORTVERSION}
DOS2UNIX_GLOB=	*.[ch] *.tcl *.msg *.in *.test license.terms

# We don't need the bundled libraries:
EXTRACT_AFTER_ARGS=	--exclude 'config.*' --exclude Makefile --exclude \
			'compat' --exclude win
MAKE_ARGS+=	INSTALL_ROOT="${STAGEDIR}"
CONFIGURE_ENV=	WRKDIR="${WRKDIR}"
CONFIGURE_ARGS+=--enable-shared --disable-stubs

post-patch:
	${REINPLACE_CMD} -E -e 's,"(zlib|tiff|jpeg|png)tcl.h",<\1.h>,' \
		-e 's,jpeg\.h,jpeglib.h,' ${WRKSRC}/*/*.[ch]
.for d in jpeg png tiff zlib
	${TOUCH} ${WRKDIR}/$dtclConfig.sh
.endfor

post-configure:
.for l in jpeg png tiff
	# Link with -l$l
	${REINPLACE_CMD} -E \
		-e 's,^SHLIB_LD_LIBS[[:space:]]*=[[:space:]]*(.*),SHLIB_LD_LIBS=\1 -l$l,' \
		${WRKSRC}/$l/Makefile
.endfor

do-test:
	cd ${WRKSRC}/tests && \
		${SETENV} TCLLIBPATH=${WRKSRC:Q} ${WISH} ${WRKSRC}/tests/all

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_DATA} ${WRKSRC}/msgs/*.msg ${STAGEDIR}${EXAMPLESDIR}/msgs/
	${INSTALL_SCRIPT} ${WRKSRC}/demo.tcl ${WRKSRC}/tkv.tcl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
