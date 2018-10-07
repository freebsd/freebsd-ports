# Created by: Slava Shwartsman <slavash@FreeBSD.org>
# $FreeBSD$

PORTNAME=	perftest
DISTVERSIONPREFIX=	V
DISTVERSION=	4.4-0.3
CATEGORIES=	benchmarks

MAINTAINER=	slavash@FreeBSD.org
COMMENT=	Collection of tests for RDMA micro-benchmark

LICENSE=	LGPL21 BSD2CLAUSE
LICENSE_COMB=	dual

.if !exists(/usr/lib/libibverbs.so)
IGNORE=		missing OFED user space
.endif

USES=		autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	linux-rdma

GNU_CONFIGURE=yes

.include <bsd.port.mk>
