# ex:ts=8
# New ports collection makefile for:	bzip2
# Version required:	0.9.0c
# Date created:		19 Nov 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bzip2-0.9.5d
CATEGORIES=	archivers
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/bzip2/v095/ \
		http://www.kernel.org/pub/software/utils/compress/bzip2/

MAINTAINER=	obrien@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
MAN1=		bzip2.1
MLINKS=		bzip2.1 bunzip2.1   bzip2.1 bzcat.1   bzip2.1 bz2cat.1 \
		bzip2.1 bzip2recover.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bz2cat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libbz2.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKSRC}/manual* ${PREFIX}/share/doc/bzip2
	${PREFIX}/bin/bzip2 ${PREFIX}/share/doc/bzip2/manual.ps
.endif

.include <bsd.port.mk>
