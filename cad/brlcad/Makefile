# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	brlcad
PORTVERSION=	7.22.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/BRL-CAD%20Source/${PORTVERSION}

MAINTAINER=	erik@brlcad.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/jama_lu.h:${PORTSDIR}/math/jama	\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		drm:${PORTSDIR}/graphics/libdrm \
		png15:${PORTSDIR}/graphics/png \
		rle:${PORTSDIR}/graphics/urt \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_BZIP2=	yes
USE_GL=		gl glu
USE_XORG=	ice inputproto sm x11 xau xdamage xdmcp xext xfixes xft xi \
		xproto xrender xscrnsaver xt xxf86vm
USE_GMAKE=	yes
USE_BISON=	build
USE_TCL=	85
USE_TK=		85
USE_LDCONFIG=	yes

PREFIX?=	${LOCALBASE}/${PORTNAME}
NO_MTREE=	yes
USE_GNOME=	gnomehack
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DBRLCAD_ENABLE_STRICT:BOOL=OFF -DBRLCAD_TOGL=SYSTEM
MANPREFIX=	${DATADIR}/${PORTVERSION}

OPTIONS_DEFINE=		OPTIMIZATION
OPTIMIZATION_DESC=	Build with optimizations
OPTIONS_DEFAULT=	OPTIMIZATION

.include "${.CURDIR}/Makefile.man"
.include <bsd.port.pre.mk>

EXTRA_LIBS=	${PTHREAD_LIBS}

.if ${PORT_OPTIONS:MOPTIMIZATION}
CMAKE_BUILD_TYPE=Release
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: invokes i386 assembler
.endif

post-patch:
	@${REINPLACE_CMD} "s+-exact Tcl 8\.5\.1+Tcl 8.5+" ${WRKSRC}/src/other/tcl/library/init.tcl
	@${REINPLACE_CMD} -e 's|{LIB_DIR}|{prefix}/libdata|' \
			${WRKSRC}/misc/pkgconfig/CMakeLists.txt

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}+g;' ${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${PREFIX}/bin/mged.sh
	${LN} -s ${PREFIX}/bin/mged.sh ${LOCALBASE}/bin/mged.sh

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test)

.include <bsd.port.post.mk>
