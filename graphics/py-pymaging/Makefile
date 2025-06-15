PORTNAME=	pymaging
DISTVERSIONPREFIX=	g
DISTVERSION=	20130908
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Pure Python imaging library
WWW=		https://pymaging.rtfd.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	ojii
GH_TAGNAME=	596a08f

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -E \
		-e "/^[[:blank:]]+version[[:blank:]]*=/s/__version__/${DISTVERSION}/" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
