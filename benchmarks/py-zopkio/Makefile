# $FreeBSD$

PORTNAME=	Zopkio
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	benchmarks python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Functional and Performance Test Framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}naarad>=1.0.15:benchmarks/py-naarad@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}kazoo>=1.1:devel/py-kazoo@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}paramiko>=1.10.1:security/py-paramiko@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}junit-xml>0:textproc/py-junit-xml@${FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	linkedin

.include <bsd.port.mk>
