# New ports collection makefile for:   bigyear
# Date created:        26 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bigyear
PORTVERSION=	20010226
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://mahon.cwx.net/sources/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to print a large (one month per page) calendar

MAN1=		bigyear.1
PLIST_FILES=	bin/bigyear

post-extract:
	${RM} ${WRKSRC}/bigyear

do-patch:
# No point wasting inodes with patches
	@(${SED} -e 's,^CFLAGS,#CFLAGS,g' ${WRKSRC}/Makefile > ${WRKSRC}/foo && \
		${MV} ${WRKSRC}/foo ${WRKSRC}/Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bigyear ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bigyear.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
