PORTNAME=	phlipple
PORTVERSION=	0.8.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flipping squares will never be the same

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		desktop-file-utils gl pkgconfig sdl dos2unix xorg
USE_GL=		gl glew glu
USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
