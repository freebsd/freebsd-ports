# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
PORTVERSION=	1.0.2
PORTREVISION=	12
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/source

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Vector based 2D animation package

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=0.04.19_1:devel/etl
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libltdl.so:devel/libltdl \
		libMagickWand-6.so:graphics/ImageMagick \
		libIlmImf.so:graphics/OpenEXR \
		libmlt.so:multimedia/mlt \
		libmng.so:graphics/libmng \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libavcodec.so:multimedia/ffmpeg \
		libdv.so:multimedia/libdv

USES=		compiler:c++11-lang iconv jpeg libtool pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	cairo glibmm libxml++26
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=| ; \
		 s|el_GR|el| ; \
		 s|ja_JP|ja| ; \
		 s|no_NO|no| ; \
		 s|pl_PL|pl| ; \
		 s|sk_SK|sk| ; \
		 s|sv_SE|sv|' \
		${WRKSRC}/configure

post-build:
# FIX LC_MESSAGES
	@${LN} -sf el_GR.gmo ${WRKSRC}/po/el.gmo
	@${LN} -sf ja_JP.gmo ${WRKSRC}/po/ja.gmo
	@${LN} -sf no_NO.gmo ${WRKSRC}/po/no.gmo
	@${LN} -sf pl_PL.gmo ${WRKSRC}/po/pl.gmo
	@${LN} -sf sk_SK.gmo ${WRKSRC}/po/sk.gmo
	@${LN} -sf sv_SE.gmo ${WRKSRC}/po/sv.gmo

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} &&  ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
