# $FreeBSD$

PORTNAME=	ncmpcpp
DISTVERSION=	0.8.2
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	https://ncmpcpp.rybczak.net/stable/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Ncurses mpd client, clone of ncmpc with some new features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libfftw3.so:math/fftw3 \
		libicudata.so:devel/icu \
		libicuuc.so:devel/icu \
		libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++14-lang iconv libtool localbase ncurses:port pkgconfig readline tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1
LDFLAGS+=	-lpthread
CONFIGURE_ENV=	BOOST_LIB_SUFFIX=""

OPTIONS_DEFINE=	CLOCK DOCS OUTPUTS TAGLIB UTF8 VISUALIZER
OPTIONS_DEFAULT=	CLOCK OUTPUTS TAGLIB UTF8 VISUALIZER
CLOCK_DESC=	clock-screen support
TAGLIB_DESC=	taglib support
OUTPUTS_DESC=	Enable outputs screen
VISUALIZER_DESC=	Enable music visualizer screen

PLIST_FILES=	bin/ncmpcpp \
		man/man1/ncmpcpp.1.gz
PORTDOCS=	AUTHORS COPYING NEWS bindings config

CLOCK_CONFIGURE_ENABLE=	clock

UTF8_CONFIGURE_ENABLE=	unicode

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_WITH=	taglib

OUTPUTS_CONFIGURE_ENABLE=	outputs

VISUALIZER_BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
