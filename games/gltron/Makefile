# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gltron
PORTVERSION=	0.70
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D worm game for two players for X Window System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gl gmake sdl
USE_GL=		gl
USE_SDL=	sdl sound
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-warn

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SDL_NET DOCS
SDL_NET_DESC=	Network Support
SDL_NET_USE=	SDL=net
SDL_NET_CONFIGURE_ENABLE=	network

DESKTOP_ENTRIES=	"GLtron" \
	"3D lightcycle game" \
	"${DATADIR}/art/default/gltron.png" \
	"gltron" \
	"Game;ArcadeGame;" \
	false

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-D|CFLAGS="$$CFLAGS -D|g ; \
		 s|-O$$enable_optimize||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^AM_CFLAGS|INCLUDES|g ; \
		 s|^AM_CXXFLAGS|INCLUDES|g ; \
		 s|-ansi -pedantic||g'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
