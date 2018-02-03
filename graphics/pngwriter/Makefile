# Created by: ijliao
# $FreeBSD$

PORTNAME=	pngwriter
PORTVERSION=	0.7.0
CATEGORIES=	graphics devel

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C++ library for creating PNG images

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

BROKEN_mips=		fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private
BROKEN_mips64=		fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private
BROKEN_powerpc64=	fails to build: ios_base.h: 'std::ios_base::ios_base(const std::ios_base&)' is private

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES EXAMPLES README PNGwriterQuickReference.pdf

USES=		cmake:outsource
CMAKE_ON=	BUILD_SHARED_LIBS PNGwriter_USE_FREETYPE
USE_GITHUB=	yes
USE_LDCONFIG=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
