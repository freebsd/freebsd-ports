# New ports collection makefile for:	q4wine
# Date created:		05 Feb 2009
# Whom:			Sergey V. Dyatko <sergey.dyatko@gmail.com>
#
# $FreeBSD$

PORTNAME=	q4wine
PORTVERSION=	0.120
CATEGORIES=	deskutils emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	QT4 front-end for WINE

BUILD_DEPENDS=	icotool:${PORTSDIR}/graphics/icoutils
RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo \
		wine:${PORTSDIR}/emulators/wine \
		wget:${PORTSDIR}/ftp/wget \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build rcc_build moc_build uic_build \
		linguist_build corelib gui sql network

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	depends on wine which is only available for i386

MAN1=		q4wine-cli.1 q4wine-helper.1 q4wine.1

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ARGS+=	-DMANPAGE_ENTRY_PATH=${MANPREFIX}/man/

OPTIONS=	DBUS "Enable DBus notification support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_DBUS)
CMAKE_ARGS+=	-DWITH_DBUS:BOOL=OFF
.else
QT_COMPONENTS+=	dbus
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
