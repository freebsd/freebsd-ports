# New ports collection makefile for:	ktritoc
# Date created:				2003-07-06
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	ktritoc
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	http://www.heni-online.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tic-tac-toe like boardgame

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes

post-patch:
	${RM} -r ${WRKSRC}/ktritoc/doc/ktritoc/dtd

.include <bsd.port.mk>
