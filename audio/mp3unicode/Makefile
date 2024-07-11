PORTNAME=	mp3unicode
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/downloads/alonbl/mp3unicode/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ID3 tags charset converter
WWW=		https://mp3unicode.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		compiler:c++11-lang iconv pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"

PLIST_FILES=	bin/mp3unicode \
		share/man/man1/mp3unicode.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/dist_doc_DATA/ s|COPYING||' ${WRKSRC}/Makefile.*

.include <bsd.port.mk>
