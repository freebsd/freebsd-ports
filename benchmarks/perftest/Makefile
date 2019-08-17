# Created by: Slava Shwartsman <slavash@FreeBSD.org>
# $FreeBSD$

PORTNAME=	perftest
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4-0.7
CATEGORIES=	benchmarks

MAINTAINER=	slavash@FreeBSD.org
COMMENT=	Collection of tests for RDMA micro-benchmark

LICENSE=	LGPL21 BSD2CLAUSE
LICENSE_COMB=	dual

.if !exists(/usr/lib/libibverbs.so)
IGNORE=		missing OFED user space
.endif

USES=		autoreconf libtool shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	linux-rdma

SHEBANG_FILES=	run_perftest_multi_devices

GNU_CONFIGURE=yes

.include <bsd.port.mk>
