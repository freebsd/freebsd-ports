# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atomix
PORTVERSION=	0.4.3
CATEGORIES=	games gnome
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~pearl/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
