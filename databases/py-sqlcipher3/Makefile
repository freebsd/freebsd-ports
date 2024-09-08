PORTNAME=	sqlcipher3
DISTVERSION=	0.5.3
CATEGORIES=	databases python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python 3 bindings for SQLCipher
WWW=		https://github.com/coleifer/sqlcipher3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher

USES=		localbase python
USE_PYTHON=	distutils autoplist pytest # unclear how to run tests, see https://github.com/coleifer/sqlcipher3/issues/26

USE_GITHUB=	yes
GH_ACCOUNT=	coleifer

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sqlcipher3/_sqlite3${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
