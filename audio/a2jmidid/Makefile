PORTNAME=	a2jmidid
PORTVERSION=	9
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ALSA to JACK MIDI bridge
WWW=		https://github.com/jackaudio/a2jmidid

LICENSE=	GPLv2+

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libjack.so:audio/jack

USES=		meson pkgconfig python:env shebangfix tar:bzip2 uidfix
SHEBANG_FILES=	a2j_control

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio

OPTIONS_DEFINE=	DBUS DEBUG
OPTIONS_DEFAULT= DBUS

OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS= libdbus-1.so:devel/dbus
DBUS_MESON_OFF=	"-Ddisable-dbus=true"

DEBUG_CFLAGS= "-DDEBUG"

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
MESON_ARGS+=	-Db_lto=false
.endif

.include <bsd.port.mk>
