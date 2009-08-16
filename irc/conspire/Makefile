# New ports collection makefile for: conspire
# Date created: Thu Jul 17 2008
# Whom: Jacob Myers (jacob@whotookspaz.org)
#
# $FreeBSD$

PORTNAME=	conspire
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	irc gnome
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	jacob@whotookspaz.org
COMMENT=	A high quality IRC client which uses a multitude of interfaces

LIB_DEPENDS=	sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		mowgli.2:${PORTSDIR}/devel/libmowgli \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	conspire-bot.1 \
	conspire.1

OPTIONS=	IPV6 "Enable IPv6 support" off \
		PLUGIN "Enable plugin support" on \
		REGEX "Enable regex substitution support" on \
		GNUTLS "Enale gnutls support" on \
		SOCKS "Build with socks5 support" off

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.endif

.if !defined(WITH_PLUGIN)
CONFIGURE_ARGS+=--disable-plugin
.endif

.if !defined(WITH_REGEX)
CONFIGURE_ARGS+=--disable-regex
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.endif

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=--enable-socks
.endif

# Create plugins directory even when no plugins are installed
post-install:
	@${MKDIR} ${PREFIX}/lib/conspire/plugins

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|GtkType|GType|g' \
		${WRKSRC}/src/fe-gtk/xtext.h

.include <bsd.port.post.mk>
