# $FreeBSD$

PORTNAME=	ncmpcpp
PORTVERSION=	0.6.2
CATEGORIES=	audio
MASTER_SITES=	http://ncmpcpp.rybczak.net/stable/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	ncurses mpd client, clone of ncmpc with some new features

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

USES=		compiler:c++11-lib iconv libtool ncurses pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	BOOST_LIB_SUFFIX=""

OPTIONS_DEFINE=	CURL CLOCK DOCS OUTPUTS TAGLIB UTF8 VISUALIZER
OPTIONS_DEFAULT=	CURL CLOCK OUTPUTS TAGLIB UTF8 VISUALIZER
CURL_DESC=	Enable fetching lyrics from the Internet
CLOCK_DESC=	clock-screen support
TAGLIB_DESC=	taglib support
OUTPUTS_DESC=	Enable outputs screen
VISUALIZER_DESC=	Enable music visualizer screen

.include <bsd.port.options.mk>

PLIST_FILES=	bin/ncmpcpp \
		man/man1/ncmpcpp.1.gz
PORTDOCS=	AUTHORS COPYING NEWS bindings config ncmpcpp-completion.bash

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	curl

CLOCK_CONFIGURE_ENABLE=	clock

UTF8_CONFIGURE_ENABLE=	unicode

TAGLIB_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
TAGLIB_CONFIGURE_WITH=	taglib

OUTPUTS_CONFIGURE_ENABLE=	outputs

VISUALIZER_BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
VISUALIZER_CONFIGURE_ENABLE=	visualizer

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} == /usr
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bindings ${WRKSRC}/doc/config ${WRKSRC}/doc/ncmpcpp-completion.bash ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
