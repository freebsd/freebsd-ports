# New ports collection makefile for:	xscavenger
# Date created:		19 Feb 1998
# Whom:			eivind
#
# $FreeBSD$
#

PORTNAME=	xscavenger
PORTVERSION=	1.4.4
CATEGORIES=	games
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Lode Runner clone for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_IMAKE=	yes
MAN6=		scavenger.6

pre-configure:
	@${LN} -sf scavenger.6 ${WRKSRC}/scavenger.man
	@${ECHO_CMD} "MANSUFFIX=6" >> ${WRKSRC}/Imakefile

.include <bsd.port.mk>
