PORTNAME=	lief
DISTVERSION=	0.12.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Library to instrument executable formats
WWW=		https://github.com/lief-project/lief

LICENSE=	APACHE20

USES=		cmake:indirect python zip
USE_PYTHON=	concurrent distutils

PY_VER=		${PYTHON_VER:S/.//}
PLIST_SUB=	PY_VER=${PY_VER}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/lief.cpython-${PY_VER}.so

.include <bsd.port.mk>
