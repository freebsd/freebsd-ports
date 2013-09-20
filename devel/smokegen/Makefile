# $FreeBSD$

PORTNAME=	smokegen
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdeprefix
USE_QT4=	corelib xml qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DSMOKE_CMAKE_MODULE_DIR:PATH=${PREFIX}/lib/cmake/smoke
USE_LDCONFIG=	yes

NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's|share/smoke/cmake|lib/cmake/smoke|g' \
		${WRKSRC}/smokebase/CMakeLists.txt

.include <bsd.port.mk>
