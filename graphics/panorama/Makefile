# New ports collection makefile for:	panorama
# Date created:				14 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	panorama
PORTVERSION=	0.18.01
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU framework for 3D graphics production

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_BZIP2=	yes
USE_BISON=	yes
USE_GNOME=	gnometarget gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
INSTALLS_SHLIB=	yes

IGNORE=		segfaults on startup (GUI only, render binary still works)

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-module -rpath|-module -avoid-version -rpath|g'
	@${REINPLACE_CMD} -e 's,/etc/,/etc/panorama/,' ${WRKSRC}/programs/gui/main.cpp \
		${WRKSRC}/programs/render/render.cpp ${WRKSRC}/doc/config.in

.include <bsd.port.mk>
