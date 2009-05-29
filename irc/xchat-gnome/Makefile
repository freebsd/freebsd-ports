# New ports collection makefile for:	xchat-gnome
# Date created:			04 May 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	xchat
PORTVERSION=	0.26.1
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/xchat-gnome/${PORTVERSION:R}
PKGNAMESUFFIX=	-gnome
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	An IRC client for GNOME 2 (development version)

LIB_DEPENDS=	sexy:${PORTSDIR}/x11-toolkits/libsexy \
		notify:${PORTSDIR}/devel/libnotify

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui gnomedocutils desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-tcl
GCONF_SCHEMAS=	apps_xchat.schemas notification.schemas urlscraper.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
WANT_PERL=	yes

MAN1=		xchat-gnome.1

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
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
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include/tcl8.3" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} \
		-L${LOCALBASE}/lib/tcl8.3"
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--enable-tcl=no
PLIST_SUB+=	TCL="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_PERL)
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.endif

pre-everything::
.if !defined(WITH_PYTHON) || !defined(WITH_SOCKS) || !defined(WITH_TCL)
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

post-patch:
	@${REINPLACE_CMD} -E -e 's|PY_LIBS=.*|PY_LIBS="-L\$$PY_EXEC_PREFIX/lib/python\$$PY_VER/config -lpython\$$PY_VER ${PTHREAD_LIBS} -lutil"|' \
		-e 's|tcl-8.4/lib|lib/tcl8.3|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
