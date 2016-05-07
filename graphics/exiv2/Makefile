# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.24
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		cpe gettext gmake iconv libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

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
