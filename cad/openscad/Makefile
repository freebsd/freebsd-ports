# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2014.03
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://files.openscad.org/
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	The programmer's solid 3D CAD modeller

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libCGAL.so:${PORTSDIR}/math/cgal \
		libopencsg.so:${PORTSDIR}/graphics/opencsg

USES=		bison desktop-file-utils pkgconfig qmake
USE_GL=		glu glew
USE_QT4=	corelib gui opengl moc_build uic_build rcc_build
PLIST_SUB=	PORTVERSION=${PORTVERSION}
QMAKE_ENV=	EIGENDIR=${LOCALBASE}/include/eigen3
QMAKE_ARGS+=	VERSION=${PORTVERSION} \
		QMAKE_LEX=${LOCALBASE}/bin/flex \
		QMAKE_YAC=${LOCALBASE}/bin/bison
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/openscad.pro

.include <bsd.port.mk>
