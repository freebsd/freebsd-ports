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

MAINTAINER=	ports@FreeBSD.org
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
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
INSTALLS_SHLIB=	yes

CXX+=		${CPPFLAGS} ${LDFLAGS}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not link render"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-module -rpath|-module -avoid-version -rpath|g'

.include <bsd.port.post.mk>
