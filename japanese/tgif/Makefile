# New ports collection makefile for:	tgif-j
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.16
CATEGORIES=	japanese
MASTER_SITES=	http://home.jp.FreeBSD.org/~mita/LOCAL_PORTS/
DISTNAME=	ja-${PORTNAME}-980222

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/Tgif ${PREFIX}/lib/X11/app-defaults/

.include <bsd.port.mk>
