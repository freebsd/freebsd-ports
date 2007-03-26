# New ports collection makefile for:	xchat2
# Date created:			17 Aug 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/irc/xchat/Makefile,v 1.1 2006/10/26 08:33:06 marcus Exp $
#

PORTNAME=	xchat
PORTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://xchat.org/files/source/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/
MASTER_SITE_SUBDIR=	${PORTNAME:S|2||}
DISTNAME=	xchat-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An X11 IRC client using the GTK+ 2 toolkit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-nls \
		--enable-ipv6

CONFLICTS=	xchat-1* xchat-systray-plugin-[0-9]*

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

# openssl in now default in configure

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl83.1:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=--enable-tcl=${LOCALBASE}/lib/tcl8.3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include/tcl8.3" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} \
		-L${LOCALBASE}/lib/tcl8.3"
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--enable-tcl=no
PLIST_SUB+=	TCL="@comment "
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	apps_xchat_url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-spell=gtkspell
.else
CONFIGURE_ARGS+=--disable-spell
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 || defined(WITHOUT_PERL)
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.endif

pre-everything::
.if !defined(WITH_PYTHON) || !defined(WITH_SOCKS) || !defined(WITH_TCL) || !defined(WITHOUT_PERL) || !defined(WITHOUT_DBUS) || !defined(WITHOUT_GTKSPELL)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "WITH_PYTHON=yes for Python support"
.endif
.if !defined(WITH_SOCKS)
	@${ECHO_MSG} "WITH_SOCKS=yes for SOCKS5 proxy support"
.endif
.if !defined(WITH_TCL)
	@${ECHO_MSG} "WITH_TCL=yes for tcl support"
.endif
.if !defined(WITHOUT_PERL)
	@${ECHO_MSG} "WITHOUT_PERL=yes to disable Perl support"
.endif
.if !defined(WITHOUT_DBUS)
	@${ECHO_MSG} "WITHOUT_DBUS=yes to disable dbus support"
.endif
.if !defined(WITHOUT_GTKSPELL)
	@${ECHO_MSG} "WITHOUT_GTKSPELL=yes to disable spell check support"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|PY_LIBS=.*|PY_LIBS="-L\$$PY_EXEC_PREFIX/lib/python\$$PY_VER/config -lpython\$$PY_VER ${PTHREAD_LIBS} -lutil"|' \
		${WRKSRC}/configure

# Create plugins directory even when no plugins are installed
post-install:
	@${MKDIR} ${PREFIX}/lib/xchat/plugins

.include <bsd.port.post.mk>
