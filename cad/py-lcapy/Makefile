# $FreeBSD$

PORTNAME=	lcapy
DISTVERSION=	g20171202
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Symbolic MDA Analysis Package for Linear Circuits

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	mph-
GH_TAGNAME=	23c940f
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
