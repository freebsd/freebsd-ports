# New ports collection makefile for:	py-game
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-game
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS} \
		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/numpy
LIB_DEPENDS=	SDL_ttf.2:${PORTSDIR}/graphics/sdl_ttf \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		smpeg.1:${PORTSDIR}/graphics/smpeg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/numpy

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD}
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

do-configure:
	@${SETUP_CMD} config.py

do-build:
	@${SETUP_CMD} setup.py build

do-install:
	@${SETUP_CMD} setup.py install

.include <bsd.port.mk>
