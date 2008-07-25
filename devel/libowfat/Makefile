# Ports collection Makefile for: libowfat
# Date created:			Feb 21, 2004
# Whom:				Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	libowfat
PORTVERSION=	0.27
CATEGORIES=	devel ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@web.de
COMMENT=	A general purpose library based on code by D. J. Bernstein

USE_BZIP2=	yes
USE_GMAKE=	yes

MAKEFILE=	GNUmakefile

OPTIONS=	LIBOWFAT_OPTIMIZED_CFLAGS "Use optimized CFLAGS" on

.include <bsd.port.pre.mk>

MAKE_ENV+=	INSTALL="${INSTALL}"

.if defined(WITH_LIBOWFAT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.include "${FILESDIR}/manpages"

include=	array.h buffer.h byte.h case.h cdb.h cdb_make.h dns.h errmsg.h \
		fmt.h havealloca.h io.h iob.h iopause.h ip4.h ip6.h mmap.h \
		ndelay.h open.h openreadclose.h rangecheck.h readclose.h \
		safemult.h scan.h socket.h str.h stralloc.h tai.h taia.h \
		textcode.h uint16.h uint32.h uint64.h
PLIST_DIRS=	include/libowfat
PLIST_FILES=	${include:S,^,include/libowfat/,} lib/libowfat.a
PORTDOCS=	CHANGES README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
