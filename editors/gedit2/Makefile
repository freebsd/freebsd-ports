# New ports collection makefile for:	gedit
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gedit
PORTVERSION=	0.7.9
CATEGORIES=	editors gnome
MASTER_SITES=	http://download.sourceforge.net/gedit/

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		glade.3:${PORTSDIR}/devel/libglade

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gedit.1

.include <bsd.port.mk>
