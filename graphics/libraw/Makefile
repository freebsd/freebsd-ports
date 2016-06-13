# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libraw
PORTVERSION=	0.17.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.org/data/
DISTNAME=	LibRaw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating raw images

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

USE_LDCONFIG=	yes
USES=		cpe libtool jpeg pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples --disable-jasper
CFLAGS+=	-fPIC
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DEMOSAIC_PACK_GPL2 DEMOSAIC_PACK_GPL3 DOCS EXAMPLES LCMS2 \
		OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	LCMS2

DEMOSAIC_PACK_GPL2_DESC=	Enable GPLv2 demosaic pack
DEMOSAIC_PACK_GPL3_DESC=	Enable GPLv3 demosaic pack
OPTIMIZED_CFLAGS_DESC=		Enable optimizations (on x86)
OPENMP_DESC=			Enable OpenMP (implies GCC 4.6+)

DEMOSAIC_PACK_GPL2_CONFIGURE_OFF=	--disable-demosaic-pack-gpl2
DEMOSAIC_PACK_GPL2_CONFIGURE_ON=	--enable-demosaic-pack-gpl2=../LibRaw-demosaic-pack-GPL2-${PORTVERSION}
DEMOSAIC_PACK_GPL2_DISTFILES=		LibRaw-demosaic-pack-GPL2-${PORTVERSION}.tar.gz
DEMOSAIC_PACK_GPL3_CONFIGURE_OFF=	--disable-demosaic-pack-gpl3
DEMOSAIC_PACK_GPL3_CONFIGURE_ON=	--enable-demosaic-pack-gpl3=../LibRaw-demosaic-pack-GPL3-${PORTVERSION}
DEMOSAIC_PACK_GPL3_DISTFILES=		LibRaw-demosaic-pack-GPL3-${PORTVERSION}.tar.gz
LCMS2_CONFIGURE_ENABLE=			lcms
LCMS2_LIB_DEPENDS=			liblcms2.so:graphics/lcms2
OPENMP_CONFIGURE_ENABLE=		openmp
OPENMP_USE=				GCC=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
.if ${ARCH} == "i386"
CFLAGS+=	-O3
.endif
.endif

.if ${PORT_OPTIONS:MDEMOSAIC_PACK_GPL2}
LICENSE=	GPLv2
LICENSE_COMB=	single
.endif

.if ${PORT_OPTIONS:MDEMOSAIC_PACK_GPL3}
LICENSE=	GPLv3
LICENSE_COMB=	single
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
