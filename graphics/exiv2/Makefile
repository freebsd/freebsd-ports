# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.24
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		gettext gmake iconv libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,LDFLAGS -no-undefined -lpsapi",& ;; \
		dragonfly* | freebsd*),' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
			${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/exiv2 \
		${STAGEDIR}${PREFIX}/lib/libexiv2.so.13

.include <bsd.port.mk>
