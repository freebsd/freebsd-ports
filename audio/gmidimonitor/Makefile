# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	gmidimonitor
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/gmidimonitor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ application that shows MIDI events

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		liblash.so:${PORTSDIR}/audio/lash

USES=		pkgconfig tar:bzip2 waf
USE_GNOME=	gtk20 libglade2

CONFIGURE_ARGS=	--alsa=no

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/gmidimonitor %%DATADIR%%/gmidimonitor.ui

.include <bsd.port.mk>
