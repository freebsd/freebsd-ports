# New ports collection makefile for:	grappa
# Date created:		30 June 2001
# Whom:                 dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	grappa
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.unm.edu/~moret/
DISTNAME=	GRAPPA-1.03

MAINTAINER=	dbader@eece.unm.edu
COMMENT=	Genome Rearrangements Analysis and Phylogeny Software

BUILD_DEPENDS=	${LOCALBASE}/lib/libconcorde.a:${PORTSDIR}/math/concorde

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grappa ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/grappa ${PREFIX}/bin/invdist
	${LN} -sf ${PREFIX}/bin/grappa ${PREFIX}/bin/distmat

.include <bsd.port.post.mk>
