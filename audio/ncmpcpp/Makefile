PORTNAME=	ncmpcpp
DISTVERSION=	0.9.2
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	https://ncmpcpp.rybczak.net/stable/

PATCH_SITES=	https://github.com/ncmpcpp/ncmpcpp/commit/
PATCHFILES=	d7f487c648e05172aeb2c2d0899d2086160edaf1.patch:-p1

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Ncurses mpd client, clone of ncmpc with some new features
WWW=		https://rybczak.net/ncmpcpp/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libicuuc.so:devel/icu \
		libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++14-lang gnome iconv libtool localbase ncurses \
		pkgconfig readline tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ncursesw_CFLAGS="-L${NCURSESLIB}" ncursesw_LIBS="-lncursesw"

PLIST_FILES=	bin/ncmpcpp \
		share/man/man1/ncmpcpp.1.gz
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
VISUALIZER_LIB_DEPENDS=		libfftw3.so:math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer
VISUALIZER_CONFIGURE_WITH=	fftw

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
