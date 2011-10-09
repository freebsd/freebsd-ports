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

# Depended on by textproc/p5-XML-LibRSVG
BROKEN=	Does not fetch
DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-11-06

USE_AUTOTOOLS=	libtool
WRKSRC=		${WRKDIR}/${PORTNAME}_lgpl-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	libart_lgpl-*

.include <bsd.port.mk>
