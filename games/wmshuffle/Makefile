# New ports collection makefile for:	wmshuffle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmshuffle
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.linuks.mine.nu/dockapp/ \
		ftp://regency.nsu.ru/tmp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable Shuffle game for WindowMaker and AfterStep

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
	@${MKDIR} ${DATADIR}
	@${CP} ${WRKSRC}/skin-*.xpm ${DATADIR}
	@${ECHO_MSG} "===>   Run 'wmshuffle --help' for the available options"

.include <bsd.port.mk>
