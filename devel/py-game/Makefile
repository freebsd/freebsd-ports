# New ports collection makefile for:	py-game
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-game
PORTVERSION=	1.5.2
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		smpeg.1:${PORTSDIR}/graphics/smpeg
RUN_DEPENDS=	${PYNUMERIC}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/examples/py-game
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} --unlink -C ${PREFIX}/share/examples/py-game -xf -
	${MKDIR} ${PREFIX}/share/doc/py-game
	${TAR} -C ${WRKSRC}/docs -cf - . | \
		${TAR} --unlink -C ${PREFIX}/share/doc/py-game -xf -
.endif

.include <bsd.port.mk>
