# New ports collection makefile for:	xmms-scrobbler
# Date created:							2004-12-06
# Whom:									arved
#
# $FreeBSD$

PORTNAME=		xmms-scrobbler
PORTVERSION=	0.3.5.1
CATEGORIES=		audio
MASTER_SITES=	http://www.pipian.com/stuffforchat/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		XMMS and bmp plugin for Audioscrobbler.com

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
				beep.2:${PORTSDIR}/multimedia/beep-media-player \
				musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
				curl.3:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GNOME=		gtk12 gtk20
USE_BZIP2=		yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
