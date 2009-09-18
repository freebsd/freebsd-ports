# New ports collection makefile for:	flatzebra
# Date created:				2005-10-18
# Whom:					Edwin Groothuis <edwin2mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	flatzebra
PORTVERSION=	0.1.3
CATEGORIES=	devel games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	edwin@mavetju.org
COMMENT=	A generic game engine for 2D double-buffering animation

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include

USE_AUTOTOOLS=	libtool:22
USE_SDL=	sdl mixer image
USE_GNOME=	pkgconfig

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README TODO THANKS

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|^install-data-am: .*|install-data-am: install-pkgconfigDATA|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
