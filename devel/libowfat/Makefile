# Ports collection Makefile for: libowfat
# Date created:			Feb 21, 2004
# Whom:				Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	libowfat
PORTVERSION=	0.20
CATEGORIES=	devel ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A general purpose library based on code by D. J. Bernstein

USE_BZIP2=	YES
USE_GMAKE=	YES

MAKEFILE=	GNUmakefile
MAKE_ENV+=	INSTALL="${INSTALL}"

OPTIONS=	LIBOWFAT_OPTIMIZED_CFLAGS "Use optimized CFLAGS" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LIBOWFAT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.include "${FILESDIR}/manpages"

examples=	examples/byte.c examples/str.c
examplesdir=	${EXAMPLESDIR:S,^${PREFIX}/,,}
PLIST_DIRS=	${examplesdir}
PLIST_FILES=	lib/libowfat.a ${examples:S,^examples/,${examplesdir}/,}
.if!defined(NOPORTDOCS)
PORTDOCS=	CHANGES README TODO
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${examples} ${EXAMPLESDIR}
# add installed header files to packaging list:
	@cd ${PREFIX} && \
	    ${FIND} include/libowfat -type f -o -type l | ${SORT} >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/libowfat" >>${TMPPLIST}

.include <bsd.port.post.mk>
