# ex:ts=8
# Ports collection makefile for:  bzip2
# Date created:			  19 Nov 1997
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bzip2
PORTVERSION=	1.0.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	bzip2/v100

MAINTAINER=	obrien@FreeBSD.org

INSTALLS_SHLIB=	yes

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
	${INSTALL_DATA} ${WRKSRC}/libbz2.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libbz2.so.1 ${PREFIX}/lib/libbz2.so
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKSRC}/manual* ${PREFIX}/share/doc/bzip2
	${PREFIX}/bin/bzip2 -f ${PREFIX}/share/doc/bzip2/manual.ps
.endif

.include <bsd.port.mk>
