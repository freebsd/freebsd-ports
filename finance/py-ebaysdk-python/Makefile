# $FreeBSD$
#

PORTNAME=	ebaysdk-python
PORTVERSION=	2.1.4
CATEGORIES=	finance python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	eBay API SDK for Python

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=     timotheus
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	df553c0

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
