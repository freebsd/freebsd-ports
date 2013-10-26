# $FreeBSD$

PORTNAME=	kate-plugin-pate
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kate-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for Python plugins in Kate

USE_XZ=		yes
USES=		cmake:outsource
USE_KDE4=	kdelibs kdeprefix kdehier automoc4 kate \
		pykde4_build pykde4_run
USE_QT4=	gui webkit \
		moc_build qmake_build rcc_build uic_build
USE_PYTHON=	yes

DISTINFO_FILE=	${PORTSDIR}/editors/kate/distinfo

# cmake.mk doesn't allow to overwrite BUILD_WRKSRC for out-of-source builds
_pate_WRKSRC=	${BUILD_WRKSRC}/kate/plugins/pate

NO_STAGE=	yes
do-build:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	cd ${_pate_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
