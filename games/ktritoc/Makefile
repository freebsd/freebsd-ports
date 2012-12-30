# New ports collection makefile for:	ktritoc
# Date created:				2003-07-06
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	ktritoc
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	games kde
MASTER_SITES=	http://www.heni-online.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tic-tac-toe like boardgame

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool

post-patch:
	${RM} -r ${WRKSRC}/ktritoc/doc/ktritoc/dtd

.include <bsd.port.mk>
