# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.0.5
CATEGORIES=	irc
MASTER_SITES=	http://weechat.flashtux.org/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes

CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}

MAN1=		weechat.1

PLIST_FILES=	bin/weechat-curses share/locale/fr/LC_MESSAGES/weechat.mo

post-patch:
	@${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

.include <bsd.port.mk>
