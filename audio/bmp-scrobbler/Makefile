# New ports collection makefile for:	bmp-scrobbler
# Date created:				01-14-2005
# Whom:					Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$

PORTNAME=	bmp-scrobbler
PORTVERSION=	0.3.6
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/
DISTNAME=	xmms-scrobbler-${PORTVERSION}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	BMP plugin for Audioscrobbler.com

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		beep.2:${PORTSDIR}/multimedia/beep-media-player \
		curl.3:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS=	--disable-xmms-plugin
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_APE)
CONFIGURE_ARGS+=	--enable-prefer-ape
.endif

.include <bsd.port.mk>
