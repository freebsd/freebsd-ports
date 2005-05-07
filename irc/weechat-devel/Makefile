# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.1.1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.flashtux.org/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}

MAN1=		weechat-curses.1

PLIST_FILES=	bin/weechat-curses

.for lang in fr es
PLIST_FILES+=	%%NLS%%share/locale/${lang}/LC_MESSAGES/weechat.mo
.endfor

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	@${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

.include <bsd.port.mk>
