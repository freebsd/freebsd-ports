# ex:ts=8
# New ports collection makefile for:	axel
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axel
PORTVERSION=	0.94
CATEGORIES=	ftp
MASTER_SITES=	http://www.lintux.cx/downloads/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes

MAN1=	axel.1

post-patch:
	@${PERL} -pi -e "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/axel ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/axelrc.example ${PREFIX}/etc/axelrc
	${INSTALL_MAN} ${WRKSRC}/axel.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
