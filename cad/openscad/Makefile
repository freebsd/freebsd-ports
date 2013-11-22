# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2013.01
CATEGORIES=	cad
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	The programmer's solid 3D CAD modeller

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libCGAL.so:${PORTSDIR}/math/cgal \
		libopencsg.so:${PORTSDIR}/graphics/opencsg

USES=		bison qmake
USE_GL=		glu glew
USE_QT4=	corelib gui opengl moc_build uic_build rcc_build
PLIST_SUB=	PORTVERSION=${PORTVERSION}
QMAKE_ENV=	EIGEN2DIR=${LOCALBASE}/include/eigen2
QMAKE_ARGS+=	VERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's,XXXFLEXXX,"${LOCALBASE}/bin/flex",' \
		${WRKSRC}/openscad.pro
	${REINPLACE_CMD} -e 's,XXXBISONXXX,"${LOCALBASE}/bin/bison",' \
		${WRKSRC}/openscad.pro
	${REINPLACE_CMD} -e 's,$$$$PREFIX,${PREFIX},' \
		${WRKSRC}/openscad.pro
	${REINPLACE_CMD} -e 's#/usr/local/bin/flex#${LOCALBASE}/bin/flex#g' \
		${WRKSRC}/flex.pri

.include <bsd.port.mk>
