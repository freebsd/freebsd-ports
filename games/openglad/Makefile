PORTNAME=	openglad
PORTVERSION=	0.98
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/snowstorm/OpenGlad/Openglad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of an old DOS game called Gladiator
WWW=		https://snowstorm.sourceforge.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase:ldflags sdl
USE_CXXSTD=	c++14
USE_SDL=	sdl mixer

GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="OpenGlad" "" "" "${PORTNAME}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|COPYING INSTALL|INSTALL|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/path/to/data/dir|${DATADIR}|' ${WRKSRC}/openglad.cfg

.include <bsd.port.mk>
