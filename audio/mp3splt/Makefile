# New ports collection makefile for:	audio/mp3splt
# Date created:				30.05.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	mp3splt
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	citrin@citrin.ru
COMMENT=	Utility to split mp3 and ogg files (via CUE sheets)

LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS+=--enable-oggsplt_symlink --disable-mp3splttest

OPTIONS=	NLS "Native language support" on

MAN1=		oggsplt.1 mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
LANGUAGES=	de fr
.for language in ${LANGUAGES}
PLIST_FILES+=	share/locale/${language}/LC_MESSAGES/mp3splt.mo
.endfor
.endif

.include <bsd.port.post.mk>
