# New ports collection makefile for:	pysdl_mixer
# Date created:		2005-10-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	0.0.3
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pysdlmixer/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysdl_mixer-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Pysdl_mixer is a python interface to SDL's sdl_mixer

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal

DIST_SUBDIR=	python
USE_GZIP=	yes
USE_SDL=	sdl mixer
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/pysdl_mixer-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-sdl-mixer

post-patch:
	@${REINPLACE_CMD} -e 's,"SDL","SDL-1.1",g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,SDL/SDL,SDL11/SDL,g' ${WRKSRC}/sdl_mixer.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
