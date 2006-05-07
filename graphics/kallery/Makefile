# New ports collection makefile for:   kallery
# Date created:        22 September 2002
# Whom:                Michael Collette
#
# $FreeBSD$
#

PORTNAME=	kallery
PORTVERSION=	1.0.7a
PORTREVISION=	5
CATEGORIES=	graphics www kde
MASTER_SITES=	http://kallery.kdewebdev.org/releases/

MAINTAINER=		metrol@metrol.net
COMMENT=	An image gallery generator for KDE

LIB_DEPENDS=	Magick.9:${PORTSDIR}/graphics/ImageMagick

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee \
		's|(dtd/kdex.dtd)|${LOCALBASE}/share/apps/ksgmltools2/customization/\1|' \
		${WRKSRC}/doc/en/index.docbook
.else
	@${REINPLACE_CMD} -Ee 's|(kallery po) doc|\1|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
