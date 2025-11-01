PORTNAME=	charmtimetracker
DISTVERSION=	1.12.0
PORTREVISION=	7
CATEGORIES=	deskutils

# PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Time tracker
WWW=		https://github.com/KDAB/Charm

# The top-level license file is GPLv2, but all the sources say
# (at your option) GPLv2+ .
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned upstream, upstream repo archived Sep 24, 2023
EXPIRATION_DATE=2025-12-31

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake compiler:c++11-lib pkgconfig qt:5 xorg
CMAKE_ARGS=	-DCharm_VERSION:STRING=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	Charm

USE_QT=		core dbus gui \
		network printsupport script sql sql-sqlite3 \
		widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	ice x11 xcb xext xscrnsaver

.include <bsd.port.mk>
