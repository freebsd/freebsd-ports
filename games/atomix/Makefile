# New ports collection makefile for:   atomix
# Version required:    0.2.0-1
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	atomix-0.2.0-1
PKGNAME=	atomix-0.2.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~pearl/download/

MAINTAINER=	nakai@FreeBSD.org

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
