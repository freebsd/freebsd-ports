# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.1.4
CATEGORIES=	irc
MASTER_SITES=	http://weechat.flashtux.org/download/

MAINTAINER=	az@inec.ru
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		weechat-curses.1
INFO=		weechat_doc_en weechat_doc_es weechat_doc_fr weechat_doc_pt

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
