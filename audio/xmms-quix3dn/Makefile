# New ports collection makefile for:	xmms-quix3dn
# Date created:        			23 December 2000
# Whom:					alex
#
# $FreeBSD$
#

PORTNAME=	xmms-quix3dn
PORTVERSION=	4.4.1
CATEGORIES=	audio
MASTER_SITES=	http://nsys.by:8100/~mmts/quix/freebsd/
DISTNAME=	quix3dn-${PORTVERSION}-freebsd

MAINTAINER=	alex@FreeBSD.org

RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libquix3dn.so ${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
