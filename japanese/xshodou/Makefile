# New ports collection makefile for:   XShodou
# Date created:        11 January 1999
# Whom:                Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshodou
PORTVERSION=	1.11
CATEGORIES=	japanese tk80
MASTER_SITES=	http://wwwmiya.ee.kagu.sut.ac.jp/~sakai/

MAINTAINER=	sakai@miya.ee.kagu.sut.ac.jp

RUN_DEPENDS=    wish8.0:${PORTSDIR}/x11-toolkits/tk80

USE_X_PREFIX=	yes
MAN1=		xshodou.1
MANCOMPRESSED=	yes

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/xshodou

.include <bsd.port.mk>
