# New ports collection makefile for:   kxl
# Date created:        16 June 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxl
PORTVERSION=	1.1.7
PORTREVISION=	3
CATEGORIES=	devel games
MASTER_SITES=	http://kxl.orz.hm/download/
DISTNAME=	KXL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual, sound library for games

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_AUTOTOOLS=	libtool
USE_XORG=	xpm x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
