# New ports collection makefile for:	lmbench
# Version required:	1.0
# Date created:		6 May 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/05/14 06:08:08 asami Exp $
#

DISTNAME=	lmbench-1.0
CATEGORIES+=	benchmarking
MASTER_SITES=	ftp://forte.mathematik.uni-bremen.de/pub/unix/benchmarks/

MAINTAINER=	asami@FreeBSD.ORG

ALL_TARGET=	build

test: build
	@(cd ${WRKSRC}; make results)

retest: build
	@(cd ${WRKSRC}; make rerun)

pre-install:
	[ -d ${PREFIX}/lib/lmbench ] || mkdir -p ${PREFIX}/lib/lmbench

do-install:
	cp ${FILESDIR}/Makefile ${PREFIX}/lib/lmbench
	tar -C ${WRKSRC} -cf - Results bin scripts | \
	  tar -C ${PREFIX}/lib/lmbench -xf -
	for man in bargraph.1 graph.1; do \
	  cp ${WRKSRC}/doc/$$man ${PREFIX}/man/man1; \
	  gzip -9nf ${PREFIX}/man/man1/$$man; \
	done
	for man in bw_file_rd.8 bw_mem_cp.8 bw_mem_rd.8 bw_mem_wr.8 \
	  bw_mmap_rd.8 bw_pipe.8 bw_tcp.8 lat_connect.8 lat_ctx.8 \
	  lat_fs.8 lat_mem_rd.8 lat_mmap.8 lat_pagefault.8 lat_pipe.8 \
	  lat_proc.8 lat_rpc.8 lat_syscall.8 lat_tcp.8 lat_udp.8 \
	  lmbench.8 lmdd.8 mhz.8; do \
	  cp ${WRKSRC}/doc/$$man ${PREFIX}/man/man8; \
	  gzip -9nf ${PREFIX}/man/man8/$$man; \
	done

.include <bsd.port.mk>
