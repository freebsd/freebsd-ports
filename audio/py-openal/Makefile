# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	openal
PORTVERSION=	0.1.6
PORTREVISION=	5
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pyopenal/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenAL-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	PyOpenAL is a binding of OpenAL for Python

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		openal:al,alut python
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/PyOpenAL-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}openal
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_openal.so

.include <bsd.port.mk>
