# New ports collection makefile for:	elftoaout
# Date created:		3 Jul 1998
# Whom:			kchowksey@hss.hns.com
#
# $FreeBSD$
#

PORTNAME=	elftoaout
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.mff.cuni.cz/OS/Linux/Sparc/local/elftoaout/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELF to a.out conversion tool by Jakub Jelinek and Pete Zaitcev

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAN1=		elftoaout.1
PLIST_FILES=	bin/elftoaout

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elftoaout ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/elftoaout.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
