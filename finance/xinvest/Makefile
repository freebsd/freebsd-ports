# New ports collection makefile for:	xinvest
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

PORTNAME=	xinvest
PORTVERSION=	2.6.9
PORTREVISION=	2
CATEGORIES=	finance deskutils
MASTER_SITES=	http://xinvest.sunsite.dk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal finance tracking and performance tool

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xp xpm xt
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.inv ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
