# Created by:	Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	mp3splt
PORTVERSION=	2.4.3
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split mp3 and ogg files (via CUE sheets)

LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-oggsplt_symlink --disable-mp3splttest

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

MAN1=		oggsplt.1 mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
