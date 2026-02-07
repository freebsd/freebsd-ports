PORTNAME=	forbiddenfruit
PORTVERSION=	0.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Patch python built-in objects
WWW=		https://clarete.li/forbiddenfruit/ \
		https://github.com/clarete/forbiddenfruit

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.mit

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
