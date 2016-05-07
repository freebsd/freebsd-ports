# $FreeBSD$

PORTNAME=	ncmpcpp
PORTVERSION=	0.7.4
CATEGORIES=	audio
MASTER_SITES=	http://ncmpcpp.rybczak.net/stable/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	ncurses mpd client, clone of ncmpc with some new features

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libfftw3.so:math/fftw3 \
		libboost_filesystem.so:devel/boost-libs

USES=		compiler:c++11-lib iconv libtool ncurses:port pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CONFIGURE_ENV=	BOOST_LIB_SUFFIX=""

OPTIONS_DEFINE=	CURL CLOCK DOCS OUTPUTS TAGLIB UTF8 VISUALIZER
OPTIONS_DEFAULT=	CURL CLOCK OUTPUTS TAGLIB UTF8 VISUALIZER
CURL_DESC=	Enable fetching lyrics from the Internet
CLOCK_DESC=	clock-screen support
TAGLIB_DESC=	taglib support
OUTPUTS_DESC=	Enable outputs screen
VISUALIZER_DESC=	Enable music visualizer screen

PLIST_FILES=	bin/ncmpcpp \
		man/man1/ncmpcpp.1.gz
PORTDOCS=	AUTHORS COPYING NEWS bindings config

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

CLOCK_CONFIGURE_ENABLE=	clock

UTF8_CONFIGURE_ENABLE=	unicode

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_WITH=	taglib

OUTPUTS_CONFIGURE_ENABLE=	outputs

VISUALIZER_BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bindings ${WRKSRC}/doc/config ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
