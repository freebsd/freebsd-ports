# New ports collection makefile for:	vips
# Date created:		19 December 2003
# Whom:			Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nip
PORTVERSION=	7.8.12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/vips-7.8/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Graphical user interface for VIPS

LIB_DEPENDS=	vips.0:${PORTSDIR}/graphics/vips \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes

MAN1=		nip.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's/^EXTRA_DIST = scraps bootstrap doc/EXTRA_DIST = scraps bootstrap/' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '535,538s/^/#/' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
