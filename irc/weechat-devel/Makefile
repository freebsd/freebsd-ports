# New ports collection makefile for:	weechat
# Date created:				2003-03-07
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.org/files/src/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_BZIP2=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lua
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include"\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
WANT_GNOME=	yes
USE_GNOME=	gnomehack
WANT_PERL=	yes

OPTIONS=	RUBY		"Ruby scripting support."	Off	\
		PYTHON		"Python scripting support."	Off	\
		PERL		"Perl scripting support."	Off	\
		TCL		"TCL scripting support."	Off	\
		CHARSET		"Charset support."		On	\
		DEBUG		"Debugging."			Off	\
		ASPELL		"Spell checking."		Off	\
		GNUTLS		"GNU TLS."			Off	\
		NLS		"NLS support."			On	\
		DOCUMENTATION	"Build documentation."		Off

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=2
.else
CONFIGURE_ARGS+=	--with-debug=0
.endif

.if defined(WITHOUT_CHARSET)
CONFIGURE_ARGS+=	--disable-charset
PLIST_SUB+=	CHARSET="@comment "
.else
CONFIGURE_ARGS+=	--enable-charset
PLIST_SUB+=	CHARSET=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-nls
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
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
CONFIGURE_ARGS+=	--enable-ruby
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	RUBY="@comment "
.endif

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--enable-gnutls
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=	--enable-perl
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=	83+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib/tcl${TCL_VER}
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_DOCUMENTATION)
CONFIGURE_ARGS+=	--enable-doc
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc
BUILD_DEPENDS+=	source-highlight:${PORTSDIR}/textproc/source-highlight
PLIST_SUB+=	DOCUMENTATION=""
MAN1=		weechat-curses.1
.else
CONFIGURE_ARGS+=	--disable-doc
PLIST_SUB+=	DOCUMENTATION="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
