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
USE_PYTHON=	yes
USE_RUBY=	yes
USE_GETTEXT=	yes

MAN1=	weechat-curses.1

OPTIONS=	RUBY "Ruby scripting support." off \
		PYTHON "Python scripting support." off \
		PERL "Perl scripting support." off \
		CHARSET "Charset support." on \
		DEBUG "Debugging." off \
		ASPELL "Spell checking." off \
		GNUTLS "GNU TLS." off \
		NLS "NLS support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--with-debug=2
.else
CONFIGURE_ARGS+=	--with-debug=0
.endif

.if !defined(WITHOUT_CHARSET)
CONFIGURE_ARGS+=	--disable-charset
PLIST_SUB+=	CHARSET="@comment"
.else
PLIST_SUB+=	CHARSET=""
.endif

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITHOUT_ASPELL)
CONFIGURE_ARGS+=	--enable-aspell
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=	--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_RUBY)
CONFIGURE_ARGS+=	--enable-ruby
PLIST_SUB+=	RUBY=""
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	RUBY="@comment "
.endif

.if !defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--enable-gnutls
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if !defined(WITHOUT_PERL)
CONFIGURE_ARGS+=	--enable-perl
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.post.mk>
