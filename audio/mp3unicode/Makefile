# $FreeBSD$

PORTNAME=	mp3unicode
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ID3 tags charset converter

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USES=		iconv pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"

PLIST_FILES=	bin/mp3unicode \
		man/man1/mp3unicode.1.gz
PORTDOCS=	COPYING README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-configure:
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^install-data-am/s|install-dist_docDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
