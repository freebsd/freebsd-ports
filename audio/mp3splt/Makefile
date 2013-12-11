# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	mp3splt
PORTVERSION=	2.5.2
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split MP3 and Ogg files (via CUE sheets)

LICENSE=	GPLv2

LIB_DEPENDS=	libmp3splt.so:${PORTSDIR}/audio/libmp3splt

USES=	pkgconfig:build
NO_STAGE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oggsplt_symlink
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		oggsplt.1 mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LANGUAGES=	cs de_DE es fr_FR
.for language in ${LANGUAGES}
PLIST_FILES+=	share/locale/${language}/LC_MESSAGES/mp3splt.mo
.endfor
PLIST_DIRSTRY+=	share/locale/de_DE/LC_MESSAGES
PLIST_DIRSTRY+=	share/locale/de_DE
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.mk>
