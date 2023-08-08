PORTNAME=	mtools
PORTVERSION=	4.0.43
CATEGORIES=	emulators
MASTER_SITES=	GNU

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Tools for manipulating MS-DOS disks and images
WWW=		https://www.gnu.org/software/mtools/intro.html

LICENSE=	GPLv3

CONFLICTS_INSTALL=	multimarkdown

USES=		gmake makeinfo tar:lz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_malloc_h=no
CONFIGURE_ARGS=	--enable-xdf

SUB_FILES=	pkg-message

INFO=		mtools

OPTIONS_DEFINE=	ICONV X11
OPTIONS_DEFAULT=ICONV X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
LIB_DEPENDS+=	libiconv.so:converters/libiconv
.else
CONFIGURE_ENV+=	ac_cv_header_iconv_h=no
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		xorg
USE_XORG=	x11 sm ice xau
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
MAKE_ENV+=	WITHOUT_X11=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LOCAL_CONF_FILE/s,/etc/default,${LOCALBASE}/etc,' \
		${WRKSRC}/mtoolsPaths.h
	@${REINPLACE_CMD} -e 's|^\(SAMPLE FILE\)$$|#\1|' \
		${WRKSRC}/mtools.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mtools.conf ${STAGEDIR}${PREFIX}/etc/mtools.conf.sample

.include <bsd.port.mk>
