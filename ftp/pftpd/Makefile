# New ports collection makefile for:	vsftpd
# Date created:				17 Mar 2002
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pftpd
PORTVERSION=	0.42
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/pftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw

GNU_CONFIGURE=	yes

NO_CDROM=	License problem
NO_PACKAGE=	${NO_CDROM}

MAN1=		pftpd.1 rpad.1

post-install:
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
