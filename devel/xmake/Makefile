# New ports collection makefile for:	xmake	
# Version required:	1.05
# Date created:		28 March 1997
# Whom:			dlowe
#
# $FreeBSD$
#

DISTNAME=	xmake-1.05
CATEGORIES=	devel
MASTER_SITES=	http://www.backplane.com/xmake/ \
		ftp://atari.saturn5.com/pub/dlowe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dlowe@saturn5.com

WRKSRC=		${WRKDIR}/xmake
MAN1=		xmake.1

pre-build:
	@${RM} -rf ${WRKSRC}/obj

.include <bsd.port.mk>
