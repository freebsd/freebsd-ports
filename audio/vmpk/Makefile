# $FreeBSD$

PORTNAME=	vmpk
DISTVERSION=	0.7.1
CATEGORIES=	audio
MASTER_SITES=	https://phoenixnap.dl.sourceforge.net/project/vmpk/vmpk/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual MIDI Piano Keyboard

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrumstick-rt.so:audio/drumstick

USES=		compiler:c++11-lang cmake pkgconfig qt:5 tar:bz2
USE_QT=		core gui network svg widgets x11extras \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	xcb

CMAKE_OFF=	XSLTPROC_EXECUTABLE

OPTIONS_DEFINE=	DBUS
OPTIONS_SUB=		yes

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_USE=	qt=dbus

.include <bsd.port.mk>
