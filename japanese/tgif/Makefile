# New ports collection makefile for:	tgif-j
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.34
CATEGORIES=	japanese
MASTER_SITES=	http://home.jp.FreeBSD.org/~mita/LOCAL_PORTS/
DISTNAME=	ja-${PORTNAME}-980222

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif-nls

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
	${INSTALL_DATA} ${WRKSRC}/Tgif ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/

.include <bsd.port.mk>
