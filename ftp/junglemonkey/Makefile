# New ports collection makefile for:	junglemonkey
# Date created:        			21st April 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	junglemonkey
PORTVERSION=	0.1.6
CATEGORIES=	ftp gnome
MASTER_SITES=	http://www.junglemonkey.net/src/
DISTNAME=	jm-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		gnet.0:${PORTSDIR}/net/gnet \
		popt.0:${PORTSDIR}/devel/popt \
		glade.3:${PORTSDIR}/devel/libglade

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--enable-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		jm.1 jmlite.1 jmsearchserver.1

.include <bsd.port.mk>
