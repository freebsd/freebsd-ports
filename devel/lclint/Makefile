# New ports collection makefile for:  lclint
# Date created: 	9 September 1996
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	lclint
PORTVERSION=	2.5q
CATEGORIES=	devel
MASTER_SITES=	http://lclint.cs.virginia.edu/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.Org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
