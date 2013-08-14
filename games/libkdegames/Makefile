# $FreeBSD$

PORTNAME=	libkdegames
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE 4 games

CONFLICTS_INSTALL=	kdegames-4.[0-9].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	network phonon xml moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_OpenAL:BOOL=False
CMAKE_ARGS+=	-DWITH_SndFile:BOOL=False

.include <bsd.port.mk>
