PORTNAME=	bibtexconv
DISTVERSION=	2.0.4
CATEGORIES=	converters
MASTER_SITES=	https://www.nntb.no/~dreibh/bibtexconv/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	BibTeX Converter
WWW=		https://www.nntb.no/~dreibh/bibtexconv/download/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	pdfinfo:graphics/poppler-utils \
		zip:archivers/zip

USES=		bison cmake python:3.9+ shebangfix ssl tar:xz

SHEBANG_FILES=	src/get-author-url src/ietf2bibtex

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	EXAMPLES

# Remove trailing subdir from CMAKE_INSTALL_DOCDIR
post-patch:
	@${REINPLACE_CMD} -e 's|/examples||' \
		${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/src/Images/CMakeLists.txt

.include <bsd.port.mk>
