# New ports collection makefile for:    irsim
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	irsim
PORTVERSION=	9.4.1
CATEGORIES=	cad
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/WRL/projects/magic/6.5/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	swallace@FreeBSD.org

USE_XLIB=	yes
MAN1=		irsim.1
MAN3=		irsim-analyzer.3
MAN5=		netchange.5

# othewise patch will complain
post-extract:
	@find ${WRKSRC} -name RCS | xargs ${RM} -rf

.include <bsd.port.mk>
