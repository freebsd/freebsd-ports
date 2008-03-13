# New ports collection makefile for:	slune
# Date created:				2005-10-06
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	slune
PORTVERSION=	1.0.12
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/slune/
DISTNAME=	Slune-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D game. includes racing, car-crashing, and lots of action

RUN_DEPENDS=	soya_editor:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal \
		${PYTHON_SITELIBDIR}/pysdl_mixer/sdl_mixer.so:${PORTSDIR}/audio/py-sdl_mixer \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/py2play/level.py:${PORTSDIR}/net-p2p/py-py2play
LIB_DEPENDS=	cal3d.12:${PORTSDIR}/graphics/cal3d \
		GLEW.1:${PORTSDIR}/graphics/glew

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		yes
USE_SDL=	sdl mixer

PYDISTUTILS_PKGNAME=	Slune
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.cfg

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
