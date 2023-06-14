PORTNAME=	mysql-connector-python
PORTVERSION=	8.0.33
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL driver written in Python
WWW=		https://dev.mysql.com/doc/connector-python/en

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3.11.0:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	mysql
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PORTSCOUT=	skipv:init

OPTIONS_DEFINE=	COMPRESSION DNS GSSAPI

COMPRESSION_DESC=	Compression Support
DNS_DESC=		DNS Support

COMPRESSION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lz4>2.1.6:archivers/py-lz4@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}zstandard>0.12.0:archivers/py-zstandard@${PY_FLAVOR}
DNS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0:dns/py-dnspython@${PY_FLAVOR}
GSSAPI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gssapi>=1.6.9:security/py-gssapi@${PY_FLAVOR}

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}
post-patch:
	@${REINPLACE_CMD} -e 's|"gcc"|"${CC}"|g ; \
		s|"g++"|"${CXX}"|g' \
		${WRKSRC}/cpydist/__init__.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./unittests.py)

.include <bsd.port.post.mk>
