# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phlipple
PORTVERSION=	0.8.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flipping squares will never be the same

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libGLEW.so:${PORTSDIR}/graphics/glew

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_SDL=	sdl mixer image
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
