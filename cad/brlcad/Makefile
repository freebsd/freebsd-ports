# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	brlcad
PORTVERSION=	7.24.0
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/BRL-CAD%20Source/${PORTVERSION}

MAINTAINER=	erik@brlcad.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/jama_lu.h:${PORTSDIR}/math/jama	\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpng15.so:${PORTSDIR}/graphics/png \
		librle.so:${PORTSDIR}/graphics/urt \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_GL=		gl glu
USE_XORG=	ice inputproto sm x11 xau xcb xdamage xdmcp xext xfixes xft xi \
		xproto xrender xscrnsaver xt xxf86vm
USE_GMAKE=	yes
USES=		bison pathfix cmake pkgconfig
USE_TCL=	85
USE_TK=		85
USE_LDCONFIG=	yes

PREFIX?=	${LOCALBASE}/${PORTNAME}
NO_MTREE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DBRLCAD_ENABLE_STRICT:BOOL=OFF
MANPREFIX=	${PREFIX}/share

BROKEN_sparc64=	does not compile: invokes i386 assembler

post-patch:
	@${REINPLACE_CMD} "s+-exact Tcl 8\.5\.1+Tcl 8.5+" ${WRKSRC}/src/other/tcl/library/init.tcl
	@${REINPLACE_CMD} -e 's|{LIB_DIR}|{prefix}/libdata|' \
			${WRKSRC}/misc/pkgconfig/CMakeLists.txt

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}+g;' ${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${STAGEDIR}${PREFIX}/bin/mged.sh
	${MKDIR} ${STAGEDIR}${LOCALBASE}/bin
	${LN} -s ${PREFIX}/bin/mged.sh ${STAGEDIR}${LOCALBASE}/bin/mged.sh

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test)

.include <bsd.port.mk>
