# Ports collection makefile for:	treeviewx
# Date created:				04 August 2001
# Whom:					tonym
#
# $FreeBSD$
#

PORTNAME=	treeviewx
PORTVERSION=	0.3
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/
DISTNAME=	tv-${PORTVERSION}

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	A phylogenetic tree viewer

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.post.mk>
