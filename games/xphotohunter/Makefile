# New ports collection makefile for:	xphotohunter
# Version required:	1.3
# Date created:		12 Aug 1999
# Whom:			clive
#
# $FreeBSD$
#

DISTNAME=	xphotohunter-1.3
PKGNAME=	zh-xphotohunter-1.3
CATEGORIES=	chinese games
MASTER_SITES=	http://www.oz.nthu.edu.tw/~u860905/Xphotohunter/

MAINTAINER=	Clive Lin <clive@CirX.ORG>

LIB_DEPENDS=	Imlib.4:${PORTSDIR}/graphics/imlib

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
