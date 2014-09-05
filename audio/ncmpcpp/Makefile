# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	ncmpcpp
PORTVERSION=	0.5.10
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://unkart.ovh.org/ncmpcpp/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	ncurses mpd client, clone of ncmpc with some new features

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient \
		libfftw3.so:${PORTSDIR}/math/fftw3

USES=		iconv libtool ncurses pkgconfig tar:bzip2
USE_GCC=	any
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	automake aclocal
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	CURL CLOCK UTF8 TAGLIB OUTPUTS VISUALIZER DOCS
OPTIONS_DEFAULT=	CURL CLOCK OUTPUTS VISUALIZER
CURL_DESC=	Enable fetching lyrics from the Internet
CLOCK_DESC=	clock-screen support
TAGLIB_DESC=	taglib support
OUTPUTS_DESC=	Enable outputs screen
VISUALIZER_DESC=	Enable music visualizer screen

.include <bsd.port.options.mk>

PLIST_FILES=	bin/ncmpcpp \
		man/man1/ncmpcpp.1.gz \
		%%DOCSDIR%%/config \
		%%DOCSDIR%%/keys \
		%%DOCSDIR%%/NEWS \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/COPYING
PLIST_DIRS=	%%DOCSDIR%%

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--with-curl=no
.endif

.if ${PORT_OPTIONS:MCLOCK}
CONFIGURE_ARGS+=	--enable-clock
.else
CONFIGURE_ARGS+=	--disable-clock
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	libtag.so:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib
.else
CONFIGURE_ARGS+=	--with-taglib=no
.endif

.if ${PORT_OPTIONS:MOUTPUTS}
CONFIGURE_ARGS+=	--enable-outputs
.else
CONFIGURE_ARGS+=	--disable-outputs
.endif

.if ${PORT_OPTIONS:MVISUALIZER}
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS+=	--enable-visualizer
.endif

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} == /usr
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/AUTHORS
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/config ${STAGEDIR}${DOCSDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys ${STAGEDIR}${DOCSDIR}/keys
.endif

.include <bsd.port.post.mk>
