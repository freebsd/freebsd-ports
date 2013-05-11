# Whom:					Michael Reifenberger <mr@freebsd.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2013.01
CATEGORIES=	cad
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	The programmer's solid 3D CAD modeller

LICENSE=	GPLv2

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
#RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	GLU:${PORTSDIR}/graphics/libGLU \
		gmp:${PORTSDIR}/math/gmp \
		mpfr:${PORTSDIR}/math/mpfr \
		CGAL:${PORTSDIR}/math/cgal \
		opencsg:${PORTSDIR}/graphics/opencsg

USE_GL=		glew
USE_QT4=  qmake corelib gui opengl moc uic rcc
PLIST_SUB=      PORTVERSION=${PORTVERSION}
#MAKE_JOBS_UNSAFE=yes
QMAKE_ENV =		EIGEN2DIR=${LOCALBASE}/include/eigen2
QMAKE_FLAGS =		VERSION=${PORTVERSION}
MAKE_ENV =		INSTALL_ROOT=${DESTDIR}
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

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_FLAGS} openscad.pro

.include <bsd.port.mk>
