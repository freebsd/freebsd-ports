# New ports collection makefile for:	NADAR
# Date created:		22 April 2000
# Whom:			Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	nadar
PORTVERSION=	2.0
CATEGORIES=	games
MASTER_SITES=	http://web.ffn.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	hsakai@m8.ffn.ne.jp
COMMENT=	A network tank battle game

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		nadars.1 nadar.1
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nadar ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nadars ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nadar.1.gz ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nadars.1.gz ${MANPREFIX}/man/man1

.include <bsd.port.mk>
