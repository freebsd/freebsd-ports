# New ports collection makefile for:	panorama
# Date created:				14 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	panorama
PORTVERSION=	0.18.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	panorama

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU framework for 3D graphics production

USE_BZIP2=	yes
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		ungif:${PORTSDIR}/graphics/libungif \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_FREETYPE=	yes
USE_LIBTOOL=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
INSTALLS_SHLIB=	yes

CXX+=		${CPPFLAGS} ${LDFLAGS}

CPPFLAGS=	-I${LOCALBASE}/include/freetype1/freetype \
		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not link render"
.endif

.include <bsd.port.post.mk>
