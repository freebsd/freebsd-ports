# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	mp3splt
PORTVERSION=	2.5.1
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split MP3 and Ogg files (via CUE sheets)

LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oggsplt_symlink --disable-mp3splttest

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		oggsplt.1 mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

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

post-patch:
.if ${OSVERSION} < 800067
# getline() is GNU extension which FreeBSD only recently adopted
	@${REINPLACE_CMD} -E \
		's:getline\(&(.+, )&(.+, .+\) == )-1:fgets(\1\2NULL:' \
			${WRKSRC}/src/freedb.c
.endif

.include <bsd.port.mk>
