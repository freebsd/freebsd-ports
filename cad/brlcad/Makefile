# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	brlcad
PORTVERSION=	7.28.0
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/BRL-CAD%20Source/${PORTVERSION}

MAINTAINER=	erik@brlcad.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	does not compile: invokes i386 assembler

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

CONFLICTS_INSTALL=	py[23][0-9]-epsilon

USES=		bison cmake:insource gl pathfix pkgconfig python:env \
		shebangfix tar:bzip2 tk xorg
USE_GL=		gl glu
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft xi \
		xorgproto xrender xscrnsaver xt xxf86vm
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/conv/intaval-g.py

NO_MTREE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CMAKE_OFF=	BRLCAD_ENABLE_STRICT
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}
MANPREFIX=	${PREFIX}/${PORTNAME}/share

TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's+-exact Tcl 8\.5\.9+Tcl 8.5+' \
		${WRKSRC}/src/other/tcl/library/init.tcl
	@${REINPLACE_CMD} -e '2709s+^+include(CheckSymbolExists)+' \
		${WRKSRC}/CMakeLists.txt

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}/${PORTNAME}+g;' ${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${STAGEDIR}${PREFIX}/bin/mged.sh

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)

.include <bsd.port.mk>
