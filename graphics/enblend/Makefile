# New ports collection makefile for:	enblend
# Date created:			19 september 2004
# Whom:				cartola@openit.com.br
#
# $FreeBSD$
#

PORTNAME=	enblend
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A tool for image blending with multiresolution splines

BUILD_DEPENDS=	${LOCALBASE}/include/boost/pool/pool.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		glut.4:${PORTSDIR}/graphics/libglut \
		xmi.1:${PORTSDIR}/graphics/plotutils \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GNOME=	gnometarget
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		enblend.1
PLIST_FILES=	bin/enblend

CPPFLAGS=	-I${WRKSRC}/src/vigra_impex -I${WRKSRC}/include \
		-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math||g ; \
		 s|-g -O3||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
