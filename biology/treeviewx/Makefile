# ex:ts=8
# Ports collection makefile for:	treeviewx
# Date created:				04 August 2001
# Whom:					tonym
#
# $FreeBSD$
#

PORTNAME=	treeviewx
PORTVERSION=	0.5
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/download/${PORTVERSION}/
DISTNAME=	tv-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A phylogenetic tree viewer

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24 \
		wx_gtk2_dcsvg-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24-contrib

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WX_CONFIG="${X11BASE}/bin/wxgtk2-2.4-config"

PLIST_FILES=	bin/tv

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
