# New ports collection makefile for:	flatzebra
# Date created:				2005-10-18
# Whom:					Edwin Groothuis <edwin2mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	flatzebra
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	devel games
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/

MAINTAINER=	edwin@mavetju.org
COMMENT=	A generic game engine for 2D double-buffering animation

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include

USE_AUTOTOOLS=	libtool:22
USE_SDL=	sdl mixer image
USE_GNOME=	pkgconfig

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README TODO

.include <bsd.port.mk>
