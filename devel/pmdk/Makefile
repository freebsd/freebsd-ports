PORTNAME=	pmdk
DISTVERSION=	1.13.1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Libraries and tools to manage and access persistent memory devices
WWW=		https://pmem.io

# PMDK code is BSD3CLAUSE, jemalloc is BSD2CLAUSE,
# Valgrind headers are BSD4CLAUSE.
LICENSE=	BSD3CLAUSE BSD2CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi

DEPRECATED=	FreeBSD has been deprecated since 1.13.X and support will be dropped from 1.14 onwards
EXPIRATION_DATE=	2023-12-31
ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		autoreconf:build gmake ncurses:port pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pmem
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
DOCS_MAKE_ARGS_OFF=	DOC=n

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-FreeBSD_14
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/pmreorder
	${RM} ${STAGEDIR}${PREFIX}/man/man1/pmreorder.1.gz
	${RM} -r ${STAGEDIR}${PREFIX}/lib/pmdk_debug
	${RM} -r ${STAGEDIR}${PREFIX}/share/pmreorder
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pmempool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.1.0.0

.include <bsd.port.mk>
