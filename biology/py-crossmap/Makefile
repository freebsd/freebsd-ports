PORTNAME=	crossmap
DISTVERSION=	0.5.2
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CrossMap-${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lift over genomics coordinates between assemblies

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bx-python>0:biology/py-bx-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>0:biology/py-bigwig@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist cython distutils

.include <bsd.port.mk>
