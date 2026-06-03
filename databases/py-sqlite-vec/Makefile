PORTNAME=	sqlite-vec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite vector search extension with Python bindings
WWW=		https://github.com/asg017/sqlite-vec

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${LOCALBASE}/include/sqlite3.h:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	asg017

post-extract:
	@${MKDIR} ${WRKSRC}/sqlite_vec
	@${INSTALL_DATA} ${FILESDIR}/__init__.py ${WRKSRC}/sqlite_vec/__init__.py
	@${INSTALL_DATA} ${FILESDIR}/pyproject.toml ${WRKSRC}/pyproject.toml
	@${INSTALL_DATA} ${FILESDIR}/sqlite-vec.h ${WRKSRC}/sqlite-vec.h

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} loadable \
		VERSION=${DISTVERSION} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include -include sys/types.h"
	@${CP} ${WRKSRC}/dist/vec0.so ${WRKSRC}/sqlite_vec/vec0.so

# tests as of 0.1.9: 2 failed, 2 passed, 4 warnings, 74 errors in 4.30s: failures are due to sqlite3 missing enable_load_extension which needs to be fixed in the port

.include <bsd.port.mk>
