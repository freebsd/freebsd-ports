# New ports collection makefile for:	wmfortune
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmfortune
PORTVERSION=	0.241
PORTREVISION=	1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://dockapps.org/files/90/128/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that outputs fortune messages

PLIST_FILES=	bin/wmfortune
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfortune ${PREFIX}/bin

.include <bsd.port.mk>
