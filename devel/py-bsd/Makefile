PORTNAME=	bsd
PORTVERSION=	1.0.20220510
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python wrappers for various BSD libc and system calls
WWW=		https://github.com/freenas/py-bsd

LICENSE=	BSD3CLAUSE

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=2025-12-04
BROKEN_FreeBSD_15=	Requires deprecated header dlg_keys.h

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-bsd
GH_TAGNAME=	be67e03
USE_PYTHON=	autoplist distutils cython

.include <bsd.port.mk>
