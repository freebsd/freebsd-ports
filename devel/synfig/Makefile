# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
DISTVERSION=	0.63.05
PORTREVISION=	4
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A vector based 2D animation package

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		MagickWand:${PORTSDIR}/graphics/ImageMagick \
		jpeg:${PORTSDIR}/graphics/jpeg \
		mng:${PORTSDIR}/graphics/libmng \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		dv:${PORTSDIR}/multimedia/libdv \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26

USE_GNOME=	gnomehack glib20
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
