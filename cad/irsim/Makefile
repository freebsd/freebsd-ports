# New ports collection makefile for:    irsim
# Version required:     9.2
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

DISTNAME=       irsim-9.4.1
CATEGORIES=	cad
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/WRL/projects/magic/6.5/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	swallace@FreeBSD.org

USE_XLIB=	yes
MAN1=		irsim.1
MAN3=		irsim-analyzer.3
MAN5=		netchange.5

# othewise patch will complain
post-extract:
	@find ${WRKSRC} -name RCS | xargs ${RM} -rf

.include <bsd.port.mk>
