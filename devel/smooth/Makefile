# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	smooth
PORTVERSION=	0.9.7
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Object-oriented class library

LICENSE=	ART20

LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libcurl.so:ftp/curl \
		libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png

USES=		gmake gnome iconv jpeg localbase pkgconfig xorg
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2
USE_XORG=	x11
MAKE_ARGS=	config=systemlibcpuid

post-extract:
# Prevent accidental build/use of bundled libraries' code/headers
	@${RM} -r ${WRKSRC}/libraries/fribidi ${WRKSRC}/libraries/lib* \
		${WRKSRC}/libraries/v8 ${WRKSRC}/libraries/zlib
	@${RM} -r ${WRKSRC}/include/support

.include <bsd.port.mk>
