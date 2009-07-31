# New ports collection makefile for:	xmms-scrobbler
# Date created:							2004-12-06
# Whom:									arved
#
# $FreeBSD$

PORTNAME?=	scrobbler
PORTVERSION=	0.3.8.1
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/ \
		http://www.pipian.com/stuffforchat/
DISTNAME=	xmms-scrobbler-${PORTVERSION}

MAINTAINER?=	novel@FreeBSD.org
COMMENT?=	XMMS/BMP plugin for Audioscrobbler.com

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		curl.5:${PORTSDIR}/ftp/curl

CONFLICTS=	bmp-scrobbler-[0-9]* \
		xmms-scrobbler-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

SLAVEDIRS=	audio/xmms-scrobbler audio/bmp-scrobbler

.if !defined(WITH_XMMS) && !defined(WITH_BMP)
WITH_XMMS=	yes
WITH_BMP=	yes
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_FILES+=	lib/xmms/General/libxmms_scrobbler.la \
		lib/xmms/General/libxmms_scrobbler.so
.else
CONFIGURE_ARGS+=	--disable-xmms-plugin
.endif

.if defined(WITH_BMP)
LIB_DEPENDS+=	beep.2:${PORTSDIR}/multimedia/beep-media-player
PLIST_FILES+=	lib/bmp/General/libbmp_scrobbler.la \
		lib/bmp/General/libbmp_scrobbler.so
.else
CONFIGURE_ARGS+=	--disable-bmp-plugin
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_APE)
CONFIGURE_ARGS+=	--enable-prefer-ape
.endif

.if defined(WITH_ENCODINGS_PATCH)
USE_ICONV=	yes
.endif

post-patch::
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
.if defined(WITH_ENCODINGS_PATCH)
	@${PATCH} ${PATCH_ARGS} -p1 < ${FILESDIR}/extra-encodings-patch
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_XMMS=yes to enable xmms support"
	@${ECHO_MSG} "WITH_BMP=yes to enable beep-media-player support"
	@${ECHO_MSG} "WITH_DEBUG=yes to turn on debug mode"
	@${ECHO_MSG} "WITH_APE=yes to enable ape"
	@${ECHO_MSG} "WITH_ENCODINGS_PATCH=yes to enable ID3 tags recoding support"
	@${ECHO_MSG} " "

.include <bsd.port.mk>
