PORTNAME=	python-statsd
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	Client for Etsy's node-js statsd server
WWW=		https://github.com/WoLpH/python-statsd

LICENSE=	BSD3CLAUSE

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
