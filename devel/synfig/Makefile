# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
PORTVERSION=	0.63.05
PORTREVISION=	8
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector based 2D animation package

LICENSE=	GPLv3

BUILD_DEPENDS=	etl>=0.04.17:${PORTSDIR}/devel/etl
LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libdv.so:${PORTSDIR}/multimedia/libdv

USES=		gettext libtool pathfix pkgconfig
USE_GNOME=	cairo glibmm libxml++26
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	$$(Magick++-config --cppflags)
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=| ; \
		 /MAGICKPP_LIBS/s|-lMagick++|`Magick++-config --libs`| ; \
		 s|no_NO|no| ; \
		 s|pl_PL|pl| ; \
		 s|sk_SK|sk| ; \
		 s|el_GR|el| ; \
		 s|<tr1/|<| ; \
		 s|::tr1||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/url_fclose/s|&formatc|formatc|g' \
		${WRKSRC}/src/modules/mod_libavcodec/trgt_av.cpp
.for i in exception.h layer.h target.h time.h
	@${REINPLACE_CMD} -e \
		's|"string_decl.h"|"string.h"|' \
		${WRKSRC}/src/synfig/${i}
.endfor

post-build:
# FIX LC_MESSAGES
	@${LN} -sf no_NO.gmo ${WRKSRC}/po/no.gmo
	@${LN} -sf pl_PL.gmo ${WRKSRC}/po/pl.gmo
	@${LN} -sf sk_SK.gmo ${WRKSRC}/po/sk.gmo
	@${LN} -sf el_GR.gmo ${WRKSRC}/po/el.gmo

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} &&  ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
