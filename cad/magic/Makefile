# New ports collection makefile for:    magic
# Version required:     6.4.4
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.5 1995/04/16 08:45:49 asami Exp $
#

DISTNAME=       magic-6.4.4
CATEGORIES+=	cad
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/magic/6.4/
EXTRACT_SUFX=   .tar.Z

USE_GMAKE=	yes

do-install:
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	@(cd ${PREFIX}; chmod 555 bin/magic bin/ext2dlys bin/ext2sim bin/fsleeper bin/magicusage bin/net2ir bin/extcheck bin/X11Helper)
	@(cd ${PREFIX}; chmod 444 man/man8/prleak.8 man/man8/prleak.8 man/man1/ext2dlys.1 man/man1/ext2spice.1 man/man1/extcheck.1 man/man1/magic.1 man/man1/magicusage.1 man/man1/grsunprog.1 man/man1/ext2sim.1 man/man1/net2ir.1 man/man1/rsleeper.1 man/man1/sim2spice.1 man/man1/sleeper.1 man/man1/fsleeper.1 man/man5/cmap.5 man/man5/displays.5 man/man5/dlys.5 man/man5/sim.5 man/man5/dstyle.5 man/man5/ext.5 man/man5/glyphs.5 man/man5/magic.5 man/man5/net.5 man/man3/mpack.3 man/man3/dqueue.3 man/man3/extflat.3 man/man3/geometry.3 man/man3/hash.3 man/man3/heap.3 man/man3/libmalloc.3 man/man3/list.3 man/man3/magicutils.3 man/man3/malloc.3 man/man3/path.3 man/man3/runstats.3 man/man3/set.3 man/man3/show.3 man/man3/stack.3 man/man3/string.3 lib/mpack.h lib/libmpack.a)
	@(cd ${PREFIX}; chmod -R a+rX,go-w lib/magic)
	@(cd ${PREFIX}; strip bin/magic bin/ext2dlys bin/ext2sim bin/fsleeper bin/magicusage bin/net2ir bin/extcheck bin/X11Helper)
	@(cd ${PREFIX}; chown bin.bin bin/magic bin/ext2dlys bin/ext2sim bin/fsleeper bin/magicusage bin/net2ir bin/extcheck bin/X11Helper)
	@(cd ${PREFIX}; chown bin.bin man/man8/prleak.8 man/man8/prleak.8 man/man1/ext2dlys.1 man/man1/ext2spice.1 man/man1/extcheck.1 man/man1/magic.1 man/man1/magicusage.1 man/man1/grsunprog.1 man/man1/ext2sim.1 man/man1/net2ir.1 man/man1/rsleeper.1 man/man1/sim2spice.1 man/man1/sleeper.1 man/man1/fsleeper.1 man/man5/cmap.5 man/man5/displays.5 man/man5/dlys.5 man/man5/sim.5 man/man5/dstyle.5 man/man5/ext.5 man/man5/glyphs.5 man/man5/magic.5 man/man5/net.5 man/man3/mpack.3 man/man3/dqueue.3 man/man3/extflat.3 man/man3/geometry.3 man/man3/hash.3 man/man3/heap.3 man/man3/libmalloc.3 man/man3/list.3 man/man3/magicutils.3 man/man3/malloc.3 man/man3/path.3 man/man3/runstats.3 man/man3/set.3 man/man3/show.3 man/man3/stack.3 man/man3/string.3 lib/mpack.h lib/libmpack.a)
	@(cd ${PREFIX}; chown -R bin.bin lib/magic)
	@${MAKE} ${.MAKEFLAGS} fake-pkg

.include <bsd.port.mk>
