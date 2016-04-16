# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	borgbackup
PORTVERSION=	1.0.1
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Deduplicating backup program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.7:${PORTSDIR}/devel/py-setuptools_scm
LIB_DEPENDS=	liblz4.so:${PORTSDIR}/archivers/liblz4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.6:${PORTSDIR}/devel/py-msgpack-python

OPTIONS_DEFINE=	FUSE
FUSE_DESC=	Support to mount locally borg backup files
OPTIONS_DEFAULT=

FUSE_RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/llfuse.so:${PORTSDIR}/devel/py-llfuse

USES=		python:3.4+
USE_PYTHON=	autoplist distutils
USE_OPENSSL=	yes

# Leave py3 only ports as manual port builds.
# See https://lists.freebsd.org/pipermail/freebsd-python/2016-April/010151.html
NO_PACKAGE=	yes

.include <bsd.port.pre.mk>

# borg requires openssl>=1.0.0
.if ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/borg/*.so

.include <bsd.port.post.mk>
