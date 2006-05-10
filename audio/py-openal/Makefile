# New ports collection makefile for:	PyOpenAL
# Date created:		2005-10-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	0.1.6
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pyopenal/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenAL-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	PyOpenAL is a binding of OpenAL for Python

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.0:${PORTSDIR}/audio/freealut

DIST_SUBDIR=	python
USE_GZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/PyOpenAL-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-openal

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
