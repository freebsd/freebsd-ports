# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	bigyear
PORTVERSION=	20010226
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://mahon.cwx.net/sources/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to print a large (one month per page) calendar

MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/bigyear man/man1/bigyear.1.gz

post-extract:
	${RM} ${WRKSRC}/bigyear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bigyear ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bigyear.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
