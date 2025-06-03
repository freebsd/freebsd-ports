PORTNAME=	pyutil
DISTVERSION=	3.3.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Collection of utilities for Python programmers
WWW=		https://pypi.org/project/${PORTNAME} \
		https://github.com/tpltnt/${PORTNAME}

LICENSE=	GPLv2+ TGGPL SPL
LICENSE_COMB=	dual
LICENSE_NAME_TGGPL=	Transitive Grace Period Public Licence 1.0
LICENSE_NAME_SPL=	Simple Permissive License
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_TGGPL=	${WRKSRC}/COPYING.TGPPL.rst
LICENSE_FILE_SPL=	${WRKSRC}/COPYING.SPL.txt
LICENSE_PERMS_TGGPL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_SPL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		JSONUTIL
OPTIONS_DEFAULT=	JSONUTIL

JSONUTIL_DESC=		Install with simplejson

JSONUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

.include <bsd.port.mk>
