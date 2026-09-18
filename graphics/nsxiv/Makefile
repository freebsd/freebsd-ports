PORTNAME=	nsxiv
DISTVERSIONPREFIX=	v
DISTVERSION=	34
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple X image viewer
WWW=		https://github.com/nsxiv/nsxiv

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libImlib2.so:graphics/imlib2 \
		libinotify.so:devel/libinotify
USES=		desktop-file-utils gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xft

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		MANPREFIX=${PREFIX}/share/man \
		VERSION="${PKGVERSION}"
MAKE_ENV=	EGPREFIX=${EXAMPLESDIR} \
		LDLIBS=-linotify

INSTALL_TARGET=	install-all

CFLAGS+=	${WITH_DEBUG:U-DNDEBUG} \
		${WITH_DEBUG:D-DDEBUG -g3 -fsanitize=address,undefined}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
