# New ports collection makefile for:	xphotohunter
# Version required:	1.4
# Date created:		12 Aug 1999
# Whom:			clive
#
# $FreeBSD$
#

DISTNAME=	xphotohunter-1.4
CATEGORIES=	chinese games
MASTER_SITES=	http://www.oz.nthu.edu.tw/~u860905/Xphotohunter/

MAINTAINER=	clive@CirX.ORG

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes

post-install:
	@${ECHO} "========================================================="
	@${ECHO} "Notice: to see Chinese fonts correctly, you must set 2"
	@${ECHO} "environment variables :"
	@${ECHO} "LC_CTYPE=zh_TW.Big5"
	@${ECHO} "LC_MESSAGES=zh_TW.Big5"
	@${ECHO} " "
	@${ECHO} "========================================================="

.include <bsd.port.mk>
