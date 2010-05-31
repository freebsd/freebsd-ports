# New ports collection makefile for:	synfig
# Date created:				25 Jun 2006
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	synfig
DISTVERSION=	0.62.00
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
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		dv:${PORTSDIR}/multimedia/libdv \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26

USE_GNOME=	gnomehack gnometarget glib20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

post-patch:
	@${REINPLACE_CMD} -e '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/url_fclose/s|&formatc|formatc|g' \
		${WRKSRC}/src/modules/mod_libavcodec/trgt_av.cpp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
