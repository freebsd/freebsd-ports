# Created by: Thomas-Martin Seck <tmseck@netcologne.de>
# $FreeBSD$

PORTNAME=	libowfat
PORTVERSION=	0.29
CATEGORIES=	devel ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A general purpose library based on code by D. J. Bernstein

USES=		gmake tar:bzip2
ALL_TARGET=	dep all

MAKEFILE=	GNUmakefile

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

NO_STAGE=	yes
.include <bsd.port.pre.mk>

MAKE_ENV+=	INSTALL="${INSTALL}"

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.include "${FILESDIR}/manpages"

include=	array.h buffer.h byte.h case.h cdb.h cdb_make.h dns.h errmsg.h \
		fmt.h havealloca.h io.h iob.h iopause.h ip4.h ip6.h iarray.h \
		isset.h mmap.h ndelay.h open.h openreadclose.h rangecheck.h \
		readclose.h safemult.h scan.h socket.h str.h stralloc.h tai.h \
		taia.h textcode.h uint16.h uint32.h uint64.h va_narg.h

PLIST_DIRS=	include/libowfat
PLIST_FILES=	${include:S,^,include/libowfat/,} lib/libowfat.a
PORTDOCS=	CHANGES README TODO

post-extract:
	@${MKDIR} ${WRKSRC}/man
# Manual pages clash with other programs; prepend libowfat_ to them.
.for i in ${MAN3}
	@${MV} ${WRKSRC}/*/${i:S/libowfat_//} ${WRKSRC}/man/${i}
.endfor

post-patch:
# Clang cries when void functions return a value
	${REINPLACE_CMD} -e '56s|return ||' ${WRKSRC}/CAS.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
