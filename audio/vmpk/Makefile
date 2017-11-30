# $FreeBSD$

PORTNAME=	vmpk
DISTVERSION=	0.6.2
DISTVERSIONSUFFIX=	a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://phoenixnap.dl.sourceforge.net/project/vmpk/vmpk/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual MIDI Piano Keyboard

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrumstick-rt.so:audio/drumstick

USES=		cmake:outsource pkgconfig tar:bz2
USE_QT5=	core gui network svg widgets x11extras \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	xcb

CMAKE_ARGS=	-DXSLTPROC_EXECUTABLE="OFF"

OPTIONS_DEFINE=	DBUS
OPTIONS_SUB=		yes

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_USE=	qt5=dbus

.include <bsd.port.mk>
