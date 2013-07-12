# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phlipple
PORTVERSION=	0.8.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flipping squares will never be the same

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		GLEW:${PORTSDIR}/graphics/glew

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/*.c
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
