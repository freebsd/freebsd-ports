# $FreeBSD$

PORTNAME=	libusbmuxd
PORTVERSION=	1.0.10
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Communication interface library for usbmuxd

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libplist.so:devel/libplist

CONFLICTS_INSTALL=usbmuxd-1.0.[6-8]

USES=		libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README

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
