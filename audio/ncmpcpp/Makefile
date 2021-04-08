PORTNAME=	ncmpcpp
DISTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://ncmpcpp.rybczak.net/stable/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Ncurses mpd client, clone of ncmpc with some new features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libfftw3.so:math/fftw3 \
		libicuuc.so:devel/icu \
		libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++14-lang gnome iconv libtool localbase ncurses \
		pkgconfig readline tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ncursesw_CFLAGS="-L${NCURSESLIB}" ncursesw_LIBS="-lncursesw"

PLIST_FILES=	bin/ncmpcpp \
		man/man1/ncmpcpp.1.gz
PORTDOCS=	AUTHORS CHANGELOG.md COPYING bindings config

OPTIONS_DEFINE=	CLOCK DOCS OUTPUTS TAGLIB VISUALIZER
OPTIONS_DEFAULT=	CLOCK OUTPUTS TAGLIB VISUALIZER

CLOCK_DESC=	clock-screen support
OUTPUTS_DESC=	Enable outputs screen
TAGLIB_DESC=	taglib support
VISUALIZER_DESC=	Enable music visualizer screen

CLOCK_CONFIGURE_ENABLE=	clock
OUTPUTS_CONFIGURE_ENABLE=	outputs
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_WITH=	taglib
VISUALIZER_BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
