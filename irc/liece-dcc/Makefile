# New ports collection makefile for:	liece-dcc
# Date Created:		6 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	liece-dcc
PORTVERSION=	1.4.9
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/
DISTNAME=	liece-${PORTVERSION}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	DCC support program for Liece

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

BUILD_WRKSRC=	${WRKSRC}/dcc

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ldcc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ltcp ${PREFIX}/bin

.include <bsd.port.mk>
