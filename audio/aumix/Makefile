# New ports collection makefile for:	aumix
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aumix
PORTVERSION=	2.5
CATEGORIES=	audio
MASTER_SITES=	http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/ \
		ftp://aumix.sourceforge.net/pub/aumix/stable/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
.if !defined(NO_X11)
LIB_DEPENDS+=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG=	${X11BASE}/bin/gtk12-config
.endif

MAN1=		aumix.1 xaumix.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--enable-own-labels \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"
.if defined(NO_X11)
CONFIGURE_ARGS+=	--without-gtk
.else
pre-fetch:
	@${ECHO_MSG} -n "To build this port without X11 (and without the GUI),"
	@${ECHO_MSG} " define \"NO_X11\"."
.endif

.include <bsd.port.mk>
