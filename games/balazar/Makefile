# New ports collection makefile for:	balazar
# Date created:				2005-10-06
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	balazar
PORTVERSION=	0.2
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/balazar/
DISTNAME=	Balazar-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Balazar is a 3D adventure and roleplaying game

LIB_DEPENDS=	cal3d.11:${PORTSDIR}/graphics/cal3d \
		GLEW.1:${PORTSDIR}/graphics/glew \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	soya_editor:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal \
		${PYTHON_SITELIBDIR}/pysdl_mixer/sdl_mixer.so:${PORTSDIR}/audio/py-sdl_mixer \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/tofu/client.py:${PORTSDIR}/net/py-tofu

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED=	yes
USE_GL=		yes
USE_SDL=	sdl mixer

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
