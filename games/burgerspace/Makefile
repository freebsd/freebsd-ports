# Created by: Mark Pulford <mark@kyne.com.au>

PORTNAME=	burgerspace
PORTVERSION=	1.9.4
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	BurgerTime clone

LICENSE=	GPLv2

LIB_DEPENDS=	libflatzebra-0.1.so:devel/flatzebra

USES=		pkgconfig sdl
USE_CXXSTD=	gnu++98
USE_SDL=	image mixer sdl

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|^pkgsounddir =.*|pkgsounddir = ${DATADIR}/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
