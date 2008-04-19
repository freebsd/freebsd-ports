# New ports collection makefile for:	geki2
# Date created:				9 October 2005
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	geki2
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kxl.hn.org/download/ \
		http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-KXL-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	2D length scroll shooting game

BUILD_DEPENDS=	${LOCALBASE}/include/KXL.h:${PORTSDIR}/devel/kxl
RUN_DEPENDS=	${LOCALBASE}/lib/libKXL-1.1.7.so:${PORTSDIR}/devel/kxl

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
