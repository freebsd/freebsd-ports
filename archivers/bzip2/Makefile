# ex:ts=8
# New ports collection makefile for:	bzip2
# Version required:	0.9.0c
# Date created:		19 Nov 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/11/03 07:05:20 obrien Exp $
#

DISTNAME=	bzip2-0.9.0c
CATEGORIES=	archivers
MASTER_SITES=	http://www.muraroa.demon.co.uk/

MAINTAINER=	obrien@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
MAN1=		bzip2.1
MLINKS=		bzip2.1 bunzip2.1 bzip2.1 bzcat.1 bzip2.1 bzip2recover.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libbz2.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKSRC}/manual* ${PREFIX}/share/doc/bzip2
.endif

.include <bsd.port.mk>
