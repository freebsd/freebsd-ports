# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	pdf2djvu
PORTVERSION=	0.7.21
PORTREVISION=	6
CATEGORIES=	converters
MASTER_SITES=	https://bitbucket.org/jwilk/pdf2djvu/downloads/

MAINTAINER=	darcsis@gmail.com
COMMENT=	Pdf2djvu creates DjVu files from PDF files

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:devel/pstreams
LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libdjvulibre.so:graphics/djvulibre

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake pkgconfig tar:xz

PLIST_FILES=	bin/pdf2djvu man/man1/pdf2djvu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
