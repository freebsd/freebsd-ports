PORTNAME=	libzfs
PORTVERSION=	1.1.2023020700
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freqlabs@FreeBSD.org
COMMENT=	Python libzfs bindings
WWW=		https://github.com/freenas/py-libzfs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	truenas
GH_PROJECT=	py-libzfs
GH_TAGNAME=	c1bd4a0

HAS_CONFIGURE=	yes
USES=		compiler:c11 python
USE_PYTHON=	autoplist distutils cython

CONFIGURE_ENV=	freebsd_src=${SRC_BASE}
MAKE_ENV=	freebsd_src=${SRC_BASE}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500018 || (${OSVERSION} >= 1401000 && ${OSVERSION} < 1500000))
EXTRA_PATCHES+=	${FILESDIR}/extra-zpool-add.patch
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files in ${SRC_BASE}
.endif

.include <bsd.port.mk>
