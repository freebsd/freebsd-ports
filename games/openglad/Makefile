# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	openglad
PORTVERSION=	0.98
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/snowstorm/OpenGlad/Openglad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of an old DOS game called Gladiator

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer

CPPFLAGS+=	-I${LOCALBASE}/include

NOT_FOR_ARCHS=	sparc64

.if defined(NOPORTDOCS)
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^docs_DOCS = |nono&|' ${WRKSRC}/Makefile.in
.endif

post-configure:
	${REINPLACE_CMD} -e 's|/path/to/data/dir|${LOCALBASE}/share/openglad|g' \
		${WRKSRC}/openglad.cfg

.include <bsd.port.mk>
