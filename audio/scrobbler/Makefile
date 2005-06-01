# New ports collection makefile for:	xmms-scrobbler
# Date created:							2004-12-06
# Whom:									arved
#
# $FreeBSD$

PORTNAME?=	scrobbler
PORTVERSION=	0.3.8.1
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/ \
		http://www.pipian.com/stuffforchat/
DISTNAME=	xmms-scrobbler-${PORTVERSION}

MAINTAINER?=	novel@FreeBSD.org
COMMENT?=	XMMS/BMP plugin for Audioscrobbler.com

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		curl.3:${PORTSDIR}/ftp/curl

CONFLICTS=	bmp-scrobbler-* \
		xmms-scrobbler-*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

SLAVEDIRS=	audio/xmms-scrobbler audio/bmp-scrobbler

.if !defined(WITH_XMMS) && !defined(WITH_BMP)
WITH_XMMS=	yes
WITH_BMP=	yes
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_FILES+=	lib/xmms/General/libxmms_scrobbler.so
.else
CONFIGURE_ARGS+=	--disable-xmms-plugin
.endif

.if defined(WITH_BMP)
LIB_DEPENDS+=	beep.2:${PORTSDIR}/multimedia/beep-media-player
PLIST_FILES+=	lib/bmp/General/libbmp_scrobbler.so
.else
CONFIGURE_ARGS+=	--disable-bmp-plugin
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_APE)
CONFIGURE_ARGS+=	--enable-prefer-ape
.endif

.include <bsd.port.mk>
