# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atomix
PORTVERSION=	0.2.0.1
CATEGORIES=	games gnome
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~pearl/download/
DISTNAME=	atomix-0.2.0-1

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
