# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libraw
PORTVERSION=	0.18.13
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.org/data/
DISTNAME=	LibRaw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for manipulating raw images

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

USE_LDCONFIG=	yes
USES=		cpe libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTEXAMPLES=	*

DEMOSAIC_PACK_VERSION=	0.18.8

OPTIONS_DEFINE=		DEMOSAIC_PACK_GPL2 DEMOSAIC_PACK_GPL3 \
			DOCS EXAMPLES JASPER JPEG LCMS2 OPENMP OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	JPEG LCMS2

DEMOSAIC_PACK_GPL2_DESC=		GPLv2 demosaic pack
DEMOSAIC_PACK_GPL2_CONFIGURE_OFF=	--disable-demosaic-pack-gpl2
DEMOSAIC_PACK_GPL2_CONFIGURE_ON=	--enable-demosaic-pack-gpl2=../LibRaw-demosaic-pack-GPL2-${DEMOSAIC_PACK_VERSION}
DEMOSAIC_PACK_GPL2_DISTFILES=		LibRaw-demosaic-pack-GPL2-${DEMOSAIC_PACK_VERSION}.tar.gz
DEMOSAIC_PACK_GPL2_VARS=		LICENSE=GPLv2+ \
					LICENSE_COMB=single

DEMOSAIC_PACK_GPL3_DESC=		GPLv3 demosaic pack
DEMOSAIC_PACK_GPL3_CONFIGURE_OFF=	--disable-demosaic-pack-gpl3
DEMOSAIC_PACK_GPL3_CONFIGURE_ON=	--enable-demosaic-pack-gpl3=../LibRaw-demosaic-pack-GPL3-${DEMOSAIC_PACK_VERSION}
DEMOSAIC_PACK_GPL3_DISTFILES=		LibRaw-demosaic-pack-GPL3-${DEMOSAIC_PACK_VERSION}.tar.gz
DEMOSAIC_PACK_GPL3_VARS=		LICENSE=GPLv3+ \
					LICENSE_COMB=single

JASPER_CONFIGURE_ENABLE=		jasper
JASPER_LIB_DEPENDS=			libjasper.so:graphics/jasper

JPEG_CONFIGURE_ENABLE=			jpeg
JPEG_USES=				jpeg

LCMS2_CONFIGURE_ENABLE=			lcms
LCMS2_LIB_DEPENDS=			liblcms2.so:graphics/lcms2

OPENMP_DESC=				OpenMP support (implies GCC)
OPENMP_CONFIGURE_ENABLE=		openmp
OPENMP_USES=				compiler:openmp

OPTIMIZED_CFLAGS_CFLAGS=		-O3

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/*.pc.in

# Use "\*" instead of "." in COPYTREE_SHARE commands as "." has
# the undesired effect of copying ".deps" directory
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
