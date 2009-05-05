# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.2.6.2
CATEGORIES=	irc
MASTER_SITES=	http://flashcode.free.fr/flashtux/weechat/ \
		http://weechat.flashtux.org/download/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_BZIP2=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lua

MAN1=	weechat-curses.1

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=2
.else
CONFIGURE_ARGS+=	--with-debug=0
.endif

.if defined(WITHOUT_CHARSET)
CONFIGURE_ARGS+=	--disable-charset
PLIST_SUBS+=	CHARSET="@comment"
.else
PLIST_SUB+=	CHARSET=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_ASPELL)
CONFIGURE_ARGS+=	--enable-aspell
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=	--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--enable-python
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
CONFIGURE_ARGS+=	--enable-ruby
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	RUBY="@comment "
.endif

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--enable-gnutls
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnu-tls
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=	--enable-perl
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
