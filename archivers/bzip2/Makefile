# New ports collection makefile for:	bzip2
# Version required:	0.1pl2
# Date created:		19 Nov 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/09/10 08:03:40 asami Exp $
#

DISTNAME=	bzip2-0.1pl2
PKGNAME=	bzip2-0.1p2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.connectnet.com/pub/bzip/ \
		http://www.muraroa.demon.co.uk/

MAINTAINER=	ports@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
MAN1=		bzip2.1
MLINKS=		bzip2.1 bunzip2.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
