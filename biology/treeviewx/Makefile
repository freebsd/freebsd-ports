# Ports collection makefile for:	treeviewx
# Date created:				04 August 2001
# Whom:					tonym
#
# $FreeBSD$
#

PORTNAME=	treeviewx
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/
DISTNAME=	tv-${PORTVERSION}

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	A phylogenetic tree viewer

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WX_CONFIG="${X11BASE}/bin/wxgtk2-2.4-config"

.include <bsd.port.mk>
