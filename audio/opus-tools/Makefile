# New ports collection makefile for:	opus-tools
# Date created:        2012-07-19
# Whom:                Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opus-tools
PORTVERSION=	0.1.4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		https://ftp.mozilla.org/pub/mozilla.org/opus/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Encode, inspect, and decode Opus files

LIB_DEPENDS=	ogg.8:${PORTSDIR}/audio/libogg \
		opus:${PORTSDIR}/audio/opus

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/opusdec bin/opusenc bin/opusinfo
MAN1=		opusdec.1 opusenc.1 opusinfo.1

.include <bsd.port.mk>
