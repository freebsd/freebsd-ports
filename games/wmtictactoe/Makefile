# New ports collection makefile for:	wmtictactoe
# Version required:		0.4
# Date created:			28 Apr 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	wmtictactoe-0.4
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://atlas.ucpel.tche.br/~acamargo/

MAINTAINER=	jim@phrantic.phear.net

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
