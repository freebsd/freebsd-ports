# New ports collection makefile for:	libart
# Date created:		8 July 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	libart
PORTVERSION=	2.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://tiger.bioinf.cs.uni-potsdam.de/free/Graphics/ \
		http://cvsup.theplanet.com/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for high-performance 2D graphics

USE_AUTOTOOLS=	libtool:22
WRKSRC=		${WRKDIR}/${PORTNAME}_lgpl-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS=	libart_lgpl-*

.include <bsd.port.mk>
