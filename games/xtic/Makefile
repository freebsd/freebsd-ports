# New ports collection makefile for:    xtic
# Date created:         22 June 1995
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	xtic
PORTVERSION=	1.12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xtic.1

post-patch:
	@${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/configure.h

.include <bsd.port.mk>
