# New ports collection makefile for:	pysdl_mixer
# Date created:		2005-10-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pysdlmixer/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysdl_mixer-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Pysdl_mixer is a python interface to SDL's sdl_mixer

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal

DIST_SUBDIR=	python
USE_SDL=	sdl mixer
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysdl_mixer
WRKSRC=		${WRKDIR}/pysdl_mixer-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-sdl-mixer

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
