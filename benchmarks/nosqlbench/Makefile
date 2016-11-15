# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nosqlbench
PORTVERSION=	0.0.${DATE}
CATEGORIES=	benchmarks databases
MASTER_SITES=	LOCAL/vg

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Micro-benchmarking NoSQL storage

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libleveldb.so:databases/leveldb

DATE=		20151214
USES=		cmake tar:bzip2

CONFLICTS=	tarantool-c

BROKEN_aarch64=		Does not build: clang does not support -march=native
BROKEN_powerpc64=	Does not build on powerpc64

post-install:
	${INSTALL_DATA} ${WRKSRC}/sources/nosqlbench.conf \
		${STAGEDIR}${PREFIX}/etc/nosqlbench.conf.sample

.include <bsd.port.mk>
