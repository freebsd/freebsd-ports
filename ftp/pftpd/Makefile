# New ports collection makefile for:	vsftpd
# Date created:				17 Mar 2002
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pftpd
PORTVERSION=	0.33
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/pftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw

GNU_CONFIGURE=	yes

NO_CDROM=	"License problem"
NO_PACKAGE=	"License problem"

post-configure:
	@${PERL} -pi -e 's/.*man8.*//g' ${WRKSRC}/Makefile

post-install:
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
