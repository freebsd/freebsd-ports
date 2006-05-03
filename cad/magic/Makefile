# New ports collection makefile for:    magic
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	magic
PORTVERSION=	7.1
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://vlsi.cornell.edu/magic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive editor for VLSI layouts

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CADDIR="${PREFIX}" X11BASE="${X11BASE}"
ALL_TARGET=	mains

BINS=	XHelper7 ext2sim ext2spice extcheck magic magicusage net2ir
MAN1=	ext2sim.1 ext2spice.1 extcheck.1 magic.1 magicusage.1
MAN3=	dqueue.3 extflat.3 geometry.3 hash.3 heap.3 libmalloc.3 list.3 \
	magicutils.3 malloc.3 path.3 runstats.3 set.3 show.3 stack.3 string.3
MAN5=	cmap.5 displays.5 dlys.5 dstyle.5 ext.5 glyphs.5 magic.5 net.5 sim.5
MAN8=	prleak.8

.include <bsd.port.pre.mk>

post-patch:
	@${EGREP} -lr '^#endif[^$$]' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(^#endif\).*|\1|g; \
		 s|\(^#else\).*|\1|g; \
		 s|include.*<varargs\.h>|include <stdarg\.h>|'
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|make |\$$\{MAKE\} |g'

do-configure:
	@cd ${WRKSRC} && ${WRKSRC}/scripts/makedbh \
		database/database.h.in database/database.h
	@${CP} ${FILESDIR}/defs.mak ${WRKSRC}/defs.mak

post-install:
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/spice2sim
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/spice2sim
.for f in ${BINS}
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/${f}
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/${f}
	@${STRIP_CMD} ${PREFIX}/bin/${f}
.endfor
.for f in ${MAN1}
	@${CHMOD} ${MANMODE} ${PREFIX}/man/man1/${f}
	@${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man/man1/${f}
.endfor
.for f in ${MAN3}
	@${CHMOD} ${MANMODE} ${PREFIX}/man/man3/${f}
	@${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man/man3/${f}
.endfor
.for f in ${MAN5}
	@${CHMOD} ${MANMODE} ${PREFIX}/man/man5/${f}
	@${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man/man5/${f}
.endfor
.for f in ${MAN8}
	@${CHMOD} ${MANMODE} ${PREFIX}/man/man8/${f}
	@${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man/man8/${f}
.endfor
	@${CHMOD} -R a+rX,go-w ${PREFIX}/lib/magic
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/magic
	@${CHMOD} ${SHAREMODE} ${PREFIX}/lib/mpack.h ${PREFIX}/lib/libmpack.a
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mpack.h		\
	  ${PREFIX}/lib/libmpack.a

.include <bsd.port.post.mk>
