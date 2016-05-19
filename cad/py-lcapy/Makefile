# $FreeBSD$

PORTNAME=	lcapy
DISTVERSION=	40de0a2
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Symbolic MDA Analysis Package for Linear Circuits

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	mph-
PORTEXAMPLES=	netlists \
		networks \
		notebooks \
		schematics

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc/examples && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
