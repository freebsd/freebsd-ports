# $FreeBSD$

PORTNAME=	kate-plugin-pate
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	editors kde kde-kde4
DISTNAME=	kate-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for Python plugins in Kate

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake:noninja kde:4 python:2.7 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 kate \
		pykde4_build pykde4_run
USE_QT=		gui webkit \
		moc_build qmake_build rcc_build uic_build

DISTINFO_FILE=	${.CURDIR:H:H}/editors/kate-kde4/distinfo

# cmake.mk doesn't allow to overwrite BUILD_WRKSRC for out-of-source builds
_pate_WRKSRC=	${BUILD_WRKSRC}/addons/kate/pate

do-build:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
