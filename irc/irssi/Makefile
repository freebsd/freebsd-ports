# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.7.28.3
CATEGORIES=	irc ipv6 gnome
MASTER_SITES=	http://xlife.dhs.org/irssi/files/
DISTNAME=	irssi-0.7.28-3

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		PropList.2:${PORTSDIR}/devel/libPropList
.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnome.4:${PORTSDIR}/x11/gnomelibs
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pthreads --without-socks --with-textui \
		--with-proplist=${LOCALBASE} --without-servertest \
		--disable-nls

.if defined(WITH_GNOME)
PLIST=		${PKGDIR}/PLIST.gnome
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

.if defined(WITH_GNOME)
CONFIGURE_ARGS+= --with-gnome
.if defined(WITH_PANEL)
CONFIGURE_ARGS+= --with-gnome-panel
.else
CONFIGURE_ARGS+= --without-gnome-panel
.endif
.else
CONFIGURE_ARGS+= --without-gnome
.endif

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.post.mk>
