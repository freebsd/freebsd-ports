# New ports collection makefile for:	lmbench
# Date created:		6 May 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	lmbench
PORTVERSION=	3.0.a9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}/development/${PORTNAME}-3.0-a9 http://thegaul.org/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.a9/-a9/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sacchi@gmail.com
COMMENT=	A system performance measurement tool

ALL_TARGET=	build
MAKE_ENV=	PATH=${PATH}:${WRKSRC}/scripts
MAN1=		bargraph.1 graph.1 pgraph.1 rccs.1
MAN3=		lmbench.3 reporting.3 results.3 timing.3
MAN8=		bw_file_rd.8 bw_mem.8 bw_mem_rd.8 bw_mmap_rd.8 \
		bw_pipe.8 bw_tcp.8 bw_unix.8 cache.8 lat_connect.8 \
		lat_ctx.8 lat_fcntl.8 lat_fifo.8 lat_fs.8 lat_http.8 \
		lat_mem_rd.8 lat_mmap.8 lat_ops.8 lat_pagefault.8 \
		lat_pipe.8 lat_proc.8 lat_rpc.8 lat_select.8 lat_sig.8 \
		lat_syscall.8 lat_tcp.8 lat_udp.8 lat_unix.8 \
		lat_unix_connect.8 line.8 lmbench.8 lmdd.8 mhz.8 \
		par_mem.8 par_ops.8 stream.8 tlb.8

USE_GMAKE=	yes

# the bindir for the PLIST is:
# (note that ./os needs to be run inside the work dir, running it
#  outside will give a different result.)
#LMBENCH_OS!=	cd ${WRKSRC}/scripts && ./os
#PLIST_SUB=	LMBENCH_OS=${LMBENCH_OS}
PLIST_SUB=	"LMBENCH_OS=$$(cd ${WRKSRC}/scripts && ./os)"

test: build
	@(cd ${WRKSRC}; make results)

retest: build
	@(cd ${WRKSRC}; make rerun)

# This version seems to think that it's checked out directly from
# bitkeeper.  It wants to look in ../SCCS/s.ChangeSet to find
# its version.  Instead, make ../SCCS/s.ChangeSet old enough that
# make won't care, and create a bk.ver file with the distname in it.
post-extract:
	${MKDIR} ${WRKSRC}/SCCS
	${TOUCH} -t 199901010000 ${WRKSRC}/SCCS/s.ChangeSet
	cd ${WRKSRC}/scripts; ./version > ${WRKSRC}/src/bk.ver

# Clean up turds from building the library.  Some systems just have
# .o, some also end up with .s, so clean up both.
post-build:
	@${RM} -f ${WRKSRC}/bin/*/*.[os]

pre-install:
	[ -d ${PREFIX}/lib/lmbench ] || ${MKDIR} ${PREFIX}/lib/lmbench

do-install:
	${CP} ${FILESDIR}/Makefile ${PREFIX}/lib/lmbench
	tar --exclude \*.orig -C ${WRKSRC} -cf - bin scripts results | \
	  tar -C ${PREFIX}/lib/lmbench -xf -
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${PREFIX}/man/man1
.endfor
.for man in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${PREFIX}/man/man3
.endfor
.for man in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${PREFIX}/man/man8
.endfor

.include <bsd.port.mk>
