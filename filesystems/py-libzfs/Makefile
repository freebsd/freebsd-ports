PORTNAME=	libzfs
PORTVERSION=	1.1.2023020700
PORTREVISION=	2
CATEGORIES=	filesystems devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
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

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1401000
EXTRA_PATCHES+=	${FILESDIR}/extra-zpool-add.patch
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files in ${SRC_BASE}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400000
PATCH_SITES=    https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=     0b2ab0594997c44e80e3fdfe9d2add106d81149a.diff:-p1 # backport of https://github.com/truenas/py-libzfs/pull/251
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
PATCH_SITES=    https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=     0ce0c8be75ae4c8873824b3c6e8f0a1736cd673b.diff:-p1 # backport of https://github.com/truenas/py-libzfs/pull/297
PATCHFILES+=     9882ea5d43407b3be71621a2988e7cdaaf87aa09.diff:-p1 # backport of https://github.com/truenas/py-libzfs/pull/297
.endif

.include <bsd.port.mk>
