# $FreeBSD$

PORTNAME=	opus-tools
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		https://ftp.mozilla.org/pub/mozilla.org/opus/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Encode, inspect, and decode Opus files

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		opus:${PORTSDIR}/audio/opus

GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/opusdec bin/opusenc bin/opusinfo
MAN1=		opusdec.1 opusenc.1 opusinfo.1

.include <bsd.port.mk>
