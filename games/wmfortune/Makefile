# New ports collection makefile for:	wmfortune
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmfortune
PORTVERSION=	0.241
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.01.246.ne.jp/~m-sugano/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfortune ${PREFIX}/bin

.include <bsd.port.mk>
