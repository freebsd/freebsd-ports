# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
PORTVERSION=	0.64.3
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector based 2D animation package

LICENSE=	GPLv3

BUILD_DEPENDS=	etl>=0.04.17:${PORTSDIR}/devel/etl
LIB_DEPENDS=	libboost_program_options.so:${PORTSDIR}/devel/boost-libs \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libdv.so:${PORTSDIR}/multimedia/libdv

USES=		gettext iconv jpeg libtool pathfix pkgconfig
USE_GNOME=	cairo glibmm libxml++26
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=| ; \
		 s|el_GR|el| ; \
		 s|ja_JP|ja| ; \
		 s|no_NO|no| ; \
		 s|pl_PL|pl| ; \
		 s|sk_SK|sk| ; \
		 s|sv_SE|sv| ; \
		 s|<tr1/|<| ; \
		 s|::tr1||' \
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
