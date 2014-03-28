# Created by: arved
# $FreeBSD$

PORTNAME?=	scrobbler
PORTVERSION=	0.3.8.1
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/ \
		http://www.pipian.com/stuffforchat/
DISTNAME=	xmms-scrobbler-${PORTVERSION}

MAINTAINER?=	novel@FreeBSD.org
COMMENT?=	XMMS/BMP plugin for Audioscrobbler.com

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

CONFLICTS=	xmms-scrobbler-[0-9]*

USES=		gmake pkgconfig
USE_CSTD=	gnu89
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SLAVEDIRS=	audio/xmms-scrobbler

OPTIONS_DEFINE=	APE XMMS DEBUG ENCODINGS_PATCH
OPTIONS_DEFAULT=XMMS
XMMS_DESC=	Enable XMMS support
ENCODINGS_PATCH_DESC=	Enable ID3 tags recoding support

XMMS_LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
XMMS_PLIST_FILES=	lib/xmms/General/libxmms_scrobbler.la \
			lib/xmms/General/libxmms_scrobbler.so
XMMS_PLIST_DIRS=	lib/xmms/General lib/xmms
XMMS_CONFIGURE_ENABLE=	xmms-plugin

CONFIGURE_ARGS+=	--disable-bmp-plugin

DEBUG_CONFIGURE_ARGS=	debug

APE_CONFIGURE_ENABLE=	prefer-ape

ENCODINGS_PATCH_USES=	iconv

.include <bsd.port.options.mk>

post-patch::
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
.if ${PORT_OPTIONS:MENCODINGS_PATCH}
	@${PATCH} ${PATCH_ARGS} -p1 < ${FILESDIR}/extra-encodings-patch
.endif

.include <bsd.port.mk>
