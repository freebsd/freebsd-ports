# New ports collection makefile for:    xtic
# Date created:         22 June 1995
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	xtic
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X version of a simple but tricky board game

USE_IMAKE=	yes
USE_XORG=	xaw
MAN1=		xtic.1
PLIST_FILES=	bin/xtic

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/configure.h

.include <bsd.port.mk>
