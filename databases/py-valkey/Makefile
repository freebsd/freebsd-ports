PORTNAME=	valkey
DISTVERSION=	6.1.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Python client for Valkey forked from redis-py
WWW=		https://github.com/valkey-io/valkey-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		LIBVALKEY OCSP
OPTIONS_DEFAULT=	LIBVALKEY OCSP

LIBVALKEY_DESC=	Install valkey with libvalkey support
OCSP_DESC=	Enable support for OCSP stapling

LIBVALKEY_RUN_DEPENDS=	libvalkey>=0:databases/libvalkey
OCSP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
OCSP_USE_PYTHON=	cryptography

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31103
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=0:devel/py-async_timeout@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
