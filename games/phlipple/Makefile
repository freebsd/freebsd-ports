# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phlipple
PORTVERSION=	0.8.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flipping squares will never be the same

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		desktop-file-utils pkgconfig
USE_SDL=	sdl mixer image
USE_GL=		gl glew glu
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
