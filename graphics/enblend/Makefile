# New ports collection makefile for:	enblend
# Date created:			19 september 2004
# Whom:				cartola@openit.com.br
#
# $FreeBSD$
#

PORTNAME=	enblend
PORTVERSION=	1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cartola@openit.com.br
COMMENT=	Image Blending with Multiresolution Splines. For panorama images, etc

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/enblend
MAN1=		enblend.1

.include <bsd.port.mk>
