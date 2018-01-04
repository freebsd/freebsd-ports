# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ramlfications
PORTVERSION=	0.1.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Python parser for RAML

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=16.0.0:devel/py-attrs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonref>=0.1:devel/py-jsonref@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>=2.3.2:textproc/py-markdown2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.10.1:devel/py-xmltodict@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}

USES?=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
