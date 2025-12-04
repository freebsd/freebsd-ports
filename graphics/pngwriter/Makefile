PORTNAME=	pngwriter
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for creating PNG images
WWW=		https://pngwriter.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES EXAMPLES README PNGwriterQuickReference.pdf

USES=		cmake compiler:c++11-lang cpe
CPE_VENDOR=	${PORTNAME}_project
CMAKE_ON=	BUILD_SHARED_LIBS PNGwriter_USE_FREETYPE
USE_GITHUB=	yes
USE_LDCONFIG=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
