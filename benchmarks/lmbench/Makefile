# New ports collection makefile for:	lmbench
# Date created:		6 May 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	lmbench
PORTVERSION=	1.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.deva.net/pub/sources/system/benchmarks/ \
		ftp://ftp.kuis.kyoto-u.ac.jp/misc/benchmarks/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/utils/benchmark/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	fenner@FreeBSD.org

ALL_TARGET=	build
MAKE_ENV=	PATH=${PATH}:${WRKSRC}/scripts
MAN1=		bargraph.1 graph.1
MAN8=		bw_file_rd.8 bw_mem_cp.8 bw_mem_rd.8 bw_mem_wr.8 \
		bw_mmap_rd.8 bw_pipe.8 bw_tcp.8 lat_connect.8 lat_ctx.8 \
		lat_fs.8 lat_mem_rd.8 lat_mmap.8 lat_pagefault.8 lat_pipe.8 \
		lat_proc.8 lat_rpc.8 lat_syscall.8 lat_tcp.8 lat_udp.8 \
		lmbench.8 lmdd.8 mhz.8

test: build
	@(cd ${WRKSRC}; make results)

retest: build
	@(cd ${WRKSRC}; make rerun)

pre-install:
	[ -d ${PREFIX}/lib/lmbench ] || ${MKDIR} ${PREFIX}/lib/lmbench

do-install:
	${CP} ${FILESDIR}/Makefile ${PREFIX}/lib/lmbench
	tar -C ${WRKSRC} -cf - Results bin scripts | \
	  tar -C ${PREFIX}/lib/lmbench -xf -
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${PREFIX}/man/man1
.endfor
.for man in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${PREFIX}/man/man8
.endfor

.include <bsd.port.mk>
