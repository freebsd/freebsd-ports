# New ports collection makefile for:	enblend
# Date created:			19 september 2004
# Whom:				cartola@openit.com.br
#
# $FreeBSD$
#

PORTNAME=	enblend
PORTVERSION=	2.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Blending with Multiresolution Splines. For panorama images, etc

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		boost_date_time:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/src/vigra_impex -I${WRKSRC}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/enblend
MAN1=		enblend.1

.include <bsd.port.mk>
