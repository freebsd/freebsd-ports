PORTNAME=	boto
PORTVERSION=	2.49.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python interface to Amazon Web Services
WWW=		https://github.com/boto/boto/

LICENSE=	MIT
DEPRECATED=	This version is discontinued upstream, please use www/py-boto3
EXPIRATION_DATE=	2025-02-11

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	p5-Net-Amazon-Route53

.include <bsd.port.mk>
