# New ports collection makefile for:	xmms-scrobbler
# Date created:							2004-12-06
# Whom:									arved
#
# $FreeBSD$

PORTNAME=	xmms-scrobbler
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin for Audioscrobbler.com

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		xmms.4:${PORTSDIR}/multimedia/xmms \
		curl.3:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS=	--disable-bmp-plugin
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	lib/xmms/General/libxmms_scrobbler.so

.if defined(WITH_APE)
CONFIGURE_ARGS+=	--enable-prefer-ape
.endif

.include <bsd.port.mk>
