# New ports collection makefile for:	NADAR
# Date created:		22 April 2000
# Whom:			Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	nadar
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.seki.ee.kagu.sut.ac.jp/~sakai/myfreesoft/

MAINTAINER=	sakai@seki.ee.kagu.sut.ac.jp

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		nadars.1 nadar.1
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nadar ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nadars ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nadar.1.gz ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nadars.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
