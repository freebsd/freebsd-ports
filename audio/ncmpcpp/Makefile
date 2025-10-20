PORTNAME=	ncmpcpp
DISTVERSION=	0.10.1
PORTREVISION=	5
CATEGORIES=	audio

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Ncurses mpd client, clone of ncmpc with some new features
WWW=		https://github.com/ncmpcpp/ncmpcpp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libicuuc.so:devel/icu \
		libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c++17-lang iconv libtool ncurses \
		pkgconfig readline

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ncmpcpp \
		share/man/man1/ncmpcpp.1.gz
PORTDOCS=	AUTHORS CHANGELOG.md COPYING bindings config

OPTIONS_DEFINE=		CLOCK DOCS LTO OPTIMIZED_CFLAGS OUTPUTS TAGLIB \
			VISUALIZER
OPTIONS_DEFAULT=	CLOCK LTO OPTIMIZED_CFLAGS OUTPUTS TAGLIB VISUALIZER

CLOCK_DESC=		clock-screen support
OUTPUTS_DESC=		Enable outputs screen
TAGLIB_DESC=		taglib support
VISUALIZER_DESC=	Enable music visualizer screen

CLOCK_CONFIGURE_ENABLE=		clock

LTO_CONFIGURE_WITH=		lto

OPTIMIZED_CFLAGS_CXXFLAGS=	-ftree-vectorize -ffast-math

OUTPUTS_CONFIGURE_ENABLE=	outputs

TAGLIB_LIB_DEPENDS=		libtag.so:audio/taglib
TAGLIB_CONFIGURE_WITH=		taglib

VISUALIZER_LIB_DEPENDS=		libfftw3.so:math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer
VISUALIZER_CONFIGURE_WITH=	fftw

.include <bsd.port.options.mk>

.if ${OPSYS}_${OSREL:R} == FreeBSD_13
CONFIGURE_ENV=	ncursesw_CFLAGS="-L${NCURSESLIB}" ncursesw_LIBS="-lncursesw"
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
