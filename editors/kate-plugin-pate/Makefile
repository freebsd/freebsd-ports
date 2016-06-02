# $FreeBSD$

PORTNAME=	kate-plugin-pate
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	editors kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kate-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for Python plugins in Kate

USES=		cmake:outsource python tar:xz
USE_KDE4=	kdelibs automoc4 kate \
		pykde4_build pykde4_run
USE_QT4=	gui webkit \
		moc_build qmake_build rcc_build uic_build

DISTINFO_FILE=	${.CURDIR:H:H}/editors/kate/distinfo

# cmake.mk doesn't allow to overwrite BUILD_WRKSRC for out-of-source builds
_pate_WRKSRC=	${BUILD_WRKSRC}/addons/kate/pate

do-build:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
