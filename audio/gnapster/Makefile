# New ports collection makefile for:	gnapster
# Date created:		24 December 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnapster
PORTVERSION=	1.3.8
CATEGORIES=	audio
MASTER_SITES=	http://www.gotlinux.org/~jasta/files/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ungif.5:${PORTSDIR}/graphics/libungif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
