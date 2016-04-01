# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	gmidimonitor
PORTVERSION=	3.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/gmidimonitor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ application that shows MIDI events

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		liblash.so:audio/lash

USES=		pkgconfig tar:bzip2 waf
USE_GNOME=	gtk20 libglade2

CONFIGURE_ARGS=	--alsa=no

PLIST_FILES=	bin/gmidimonitor %%DATADIR%%/gmidimonitor.ui

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
