# New ports collection makefile for:	irssi
# Version required:		0.7.20.1
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	irssi-0.7.20.1
CATEGORIES=	irc
MASTER_SITES=	http://xlife.dhs.org/irssi/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		PropList.2:${PORTSDIR}/devel/libPropList
.if defined(USE_GNOME)
LIB_DEPENDS+=	gnome.3:${PORTSDIR}/x11/gnomelibs
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

.if defined(USE_GNOME)
CONFIGURE_ARGS+= --with-gnome
.if defined(USE_PANEL)
CONFIGURE_ARGS+= --with-gnome-panel
.else
CONFIGURE_ARGS+= --without-gnome-panel
.endif
.else
CONFIGURE_ARGS+= --without-gnome
.endif

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.mk>
