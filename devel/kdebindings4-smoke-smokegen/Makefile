# New ports collection makefile for:	kdebindings4-smoke-smokegen
# Date crated:				1 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smokegen
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdebindings-smoke-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	xml qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSMOKE_CMAKE_MODULE_DIR:PATH=${PREFIX}/lib/cmake/smoke
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|share/smoke/cmake|lib/cmake/smoke|g' \
		${WRKSRC}/smokebase/CMakeLists.txt

.include <bsd.port.mk>
