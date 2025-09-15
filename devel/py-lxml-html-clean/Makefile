PORTNAME=	lxml-html-clean
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	HTML cleaner from lxml project
WWW=		https://github.com/fedora-python/lxml_html_clean/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

.include <bsd.port.mk>
