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
COMMENT=	Multithreaded anonymous FTP daemon

GNU_CONFIGURE=	yes

RESTRICTED=	License problem

MAN1=		pftpd.1 rpad.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 501000
BROKEN=		"Does not compile"
.endif

post-install:
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.post.mk>
