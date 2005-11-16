# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://flashcode.free.fr/flashtux/weechat/ \
		http://weechat.flashtux.org/download/

MAINTAINER=	az@FreeBSD.org
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
PLIST_DIRS=	lib/weechat/plugins lib/weechat

.for lang in cs fr es
PLIST_FILES+=	%%NLS%%share/locale/${lang}/LC_MESSAGES/weechat.mo
.endfor

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_PERL)
.if ${PERL_LEVEL} < 500600
IGNORE=	This port requires perl 5.6.0 or later, Install lang/perl5 then try again
.else
CONFIGURE_ARGS+=--enable-perl
USE_PERL5=	yes
PLIST_FILES+=	lib/weechat/plugins/libperl.a lib/weechat/plugins/libperl.la \
		lib/weechat/plugins/libperl.so lib/weechat/plugins/libperl.so.0
.endif
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--enable-python
USE_PYTHON=	yes
PLIST_FILES+=	lib/weechat/plugins/libpython.a lib/weechat/plugins/libpython.la \
		lib/weechat/plugins/libpython.so lib/weechat/plugins/libpython.so.0
.endif

pre-configure:
	@${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

.include <bsd.port.post.mk>
