PORTNAME=	ebaysdk
PORTVERSION=	2.2.0
PORTREVISION=	4
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	eBay API SDK for Python
WWW=		https://github.com/timotheus/ebaysdk-python

LICENSE=	CDDL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	@${MV} ${WRKSRC}/samples ${WRKSRC}/ebaysdk/
	@${MV} ${WRKSRC}/tests ${WRKSRC}/ebaysdk/

.include <bsd.port.mk>
