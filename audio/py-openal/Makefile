# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	openal
PORTVERSION=	0.1.6
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pyopenal/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenAL-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	PyOpenAL is a binding of OpenAL for Python

OPTIONS_DEFINE=	EXAMPLES

DIST_SUBDIR=	python
USES=		openal:al,alut
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
WRKSRC=		${WRKDIR}/PyOpenAL-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-openal
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
