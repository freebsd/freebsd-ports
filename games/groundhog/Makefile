# New ports collection makefile for:	groundhog
# Date created:				23 May 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	groundhog
PORTVERSION=	1.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://home-2.tiscali.nl/~cb007736/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Groundhog, a simple logic game

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502112
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
