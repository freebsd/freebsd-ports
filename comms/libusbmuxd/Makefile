PORTNAME=	libusbmuxd
PORTVERSION=	2.0.2
CATEGORIES=	comms
MASTER_SITES=	https://github.com/libimobiledevice/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Communication interface library for usbmuxd
WWW=		https://www.libimobiledevice.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libplist-2.0.so:devel/libplist

CONFLICTS_INSTALL=usbmuxd-1.0.[6-8]

USES=		cpe libtool pathfix pkgconfig tar:bzip2
CPE_VENDOR=	libimobiledevice
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README.md

OPTIONS_DEFINE=	DOCS INOTIFY

INOTIFY_DESC=	Use inotify instead of polling (saves energy)

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
# *_CONFIGURE_WITH can't be used as --with-inotify doesn't work.
INOTIFY_CONFIGURE_OFF=	--without-inotify
INOTIFY_CFLAGS=		-I${LOCALBASE}/include
INOTIFY_LDFLAGS=	-L${LOCALBASE}/lib -linotify

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
