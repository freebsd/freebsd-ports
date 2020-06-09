# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	borgbackup
DISTVERSION=	1.1.13
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Deduplicating backup program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.7:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		python:3.4+ ssl
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		FUSE
OPTIONS_DEFAULT=	FUSE

FUSE_DESC=	Support to mount locally borg backup files
FUSE_RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/llfuse.so:devel/py-llfuse@${PY_FLAVOR}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/borg/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
