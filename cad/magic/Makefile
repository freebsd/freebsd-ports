# New ports collection makefile for:    magic
# Version required:     6.4.4
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.9 1996/10/21 07:43:40 max Exp $
#

DISTNAME=       magic-6.4.4
CATEGORIES+=	cad
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/WRL/projects/magic/6.4/
EXTRACT_SUFX=   .tar.Z

USE_GMAKE=	yes

BINS=	magic ext2dlys ext2sim fsleeper magicusage net2ir extcheck X11Helper
MAN1=	ext2dlys.1 ext2spice.1 extcheck.1 magic.1 magicusage.1		\
	grsunprog.1 ext2sim.1 net2ir.1 rsleeper.1 sim2spice.1 sleeper.1	\
	fsleeper.1
MAN3=	mpack.3 dqueue.3 extflat.3 geometry.3 hash.3 heap.3 libmalloc.3	\
	list.3 magicutils.3 malloc.3 path.3 runstats.3 set.3 show.3	\
	stack.3 string.3
MAN5=	cmap.5 displays.5 dlys.5 sim.5 dstyle.5 ext.5 glyphs.5 magic.5 net.5
MAN8=	prleak.8

post-install:
.for f in ${BINS}
	@chmod ${BINMODE} ${PREFIX}/bin/$f
	@chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/$f
	@strip ${PREFIX}/bin/$f
.endfor
.for f in ${MAN1}
	@chmod ${MANMODE} ${PREFIX}/man/man1/$f
	@chown ${MANOWN}.${MANGRP} ${PREFIX}/man/man1/$f
.endfor
.for f in ${MAN3}
	@chmod ${MANMODE} ${PREFIX}/man/man3/$f
	@chown ${MANOWN}.${MANGRP} ${PREFIX}/man/man3/$f
.endfor
.for f in ${MAN5}
	@chmod ${MANMODE} ${PREFIX}/man/man5/$f
	@chown ${MANOWN}.${MANGRP} ${PREFIX}/man/man5/$f
.endfor
.for f in ${MAN8}
	@chmod ${MANMODE} ${PREFIX}/man/man8/$f
	@chown ${MANOWN}.${MANGRP} ${PREFIX}/man/man8/$f
.endfor
	@chmod -R a+rX,go-w ${PREFIX}/lib/magic
	@chown -R ${SHAREOWN}.${SHAREGRP} ${PREFIX}/lib/magic
	@chmod ${SHAREMODE} ${PREFIX}/lib/mpack.h ${PREFIX}/lib/libmpack.a
	@chown ${SHAREOWN}.${SHAREGRP} ${PREFIX}/lib/mpack.h		\
	  ${PREFIX}/lib/libmpack.a

.include <bsd.port.mk>
