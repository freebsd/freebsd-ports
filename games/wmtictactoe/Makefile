# New ports collection makefile for:	wmtictactoe
# Version required:		1.0
# Date created:			28 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmtictactoe-1.0
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/wmtictactoe.app/wmtictactoe
USE_X_PREFIX=	yes

post-install:
	@${ECHO} "		"
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "===> Run 'wmtictactoe --help' for the available options"
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "		"

.include <bsd.port.mk>
