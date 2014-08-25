# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
DISTVERSION=	0.63.05
PORTREVISION=	6
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector based 2D animation package

# update to 0.64.1 does pick up ImageMagick correctly but there are a 
# multitude of c++ build failures which are beyond my skill to fix ..
BROKEN=		Doesn't pickup ImageMagick anymore.

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	libMagickWand-6.Q*.so:${PORTSDIR}/graphics/ImageMagick \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libdv.so:${PORTSDIR}/multimedia/libdv \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR

USE_GNOME=	gnomehack glib20 glibmm libxml++26
USES=		gettext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' -e \
		's|el_GR|el|g' -e \
		's|no_NO|no|g' -e \
		's|pl_PL|pl|g' -e \
		's|sk_SK|sk|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/url_fclose/s|&formatc|formatc|g' \
		${WRKSRC}/src/modules/mod_libavcodec/trgt_av.cpp

# FIX LC_MESSAGES
	${MV} ${WRKSRC}/po/no_NO.gmo ${WRKSRC}/po/no.gmo
	${MV} ${WRKSRC}/po/pl_PL.gmo ${WRKSRC}/po/pl.gmo
	${MV} ${WRKSRC}/po/sk_SK.gmo ${WRKSRC}/po/sk.gmo
	${MV} ${WRKSRC}/po/el_GR.gmo ${WRKSRC}/po/el.gmo

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
