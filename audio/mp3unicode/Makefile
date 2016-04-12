# $FreeBSD$

PORTNAME=	mp3unicode
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://github.com/downloads/alonbl/mp3unicode/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ID3 tags charset converter

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		iconv pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"

PLIST_FILES=	bin/mp3unicode \
		man/man1/mp3unicode.1.gz
PORTDOCS=	COPYING README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
