# Created by: Solène RAPENNE <solene@bsd.zplay.eu>

PORTNAME=	sxiv
DISTVERSIONPREFIX=	v
DISTVERSION=	26
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Lightweight image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream has archived the project; please switch to the maintained fork (graphics/nsxiv)
EXPIRATION_DATE=2022-04-01

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libgif.so:graphics/giflib \
		libImlib2.so:graphics/imlib2 \
		libinotify.so:devel/libinotify

USES=		desktop-file-utils gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	muennich
USE_XORG=	x11 xft

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV=	LDLIBS=-linotify

post-install:
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} -C ${WRKSRC}/icon install
	${INSTALL_DATA} ${WRKSRC}/sxiv.desktop ${STAGEDIR}${DESKTOPDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sxiv

.include <bsd.port.mk>
