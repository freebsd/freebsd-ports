# New ports collection makefile for:   	yagirc
# Date created:				6 July 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	yagirc
PORTVERSION=	0.66.1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		esd.2:${PORTSDIR}/audio/esound

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-pthread
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
