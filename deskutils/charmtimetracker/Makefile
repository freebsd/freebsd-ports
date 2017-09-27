# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	charmtimetracker
DISTVERSION=	1.11.4
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Time tracker

# The top-level license file is GPLv2, but all the sources say
# (at your option) GPLv2+ .
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource compiler:c++11-lib
# Use bundled keychain; the keychain is only used for KDAB-internal
# features not available or configurable in the port.
CMAKE_ARGS=	-DCharm_VERSION:STRING=${PORTVERSION} \
		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Keychain=TRUE

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	Charm

USE_QT5=	core dbus gui \
		network printsupport script sql sql-sqlite3 \
		testlib widgets xml \
		buildtools_build qmake_build
USE_XORG=	ice x11 xcb xext xscrnsaver

.include <bsd.port.mk>
