# $FreeBSD$

PORTNAME=	mp3unicode
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/downloads/alonbl/mp3unicode/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ID3 tags charset converter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		iconv pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"

PLIST_FILES=	bin/mp3unicode \
		man/man1/mp3unicode.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/dist_doc_DATA/ s|COPYING||' ${WRKSRC}/Makefile.*

.include <bsd.port.mk>
