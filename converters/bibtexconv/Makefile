PORTNAME=	bibtexconv
PORTVERSION=	1.3.6
CATEGORIES=	converters
MASTER_SITES=	https://www.nntb.no/~dreibh/bibtexconv/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	BibTeX Converter
WWW=            https://www.nntb.no/~dreibh/bibtexconv/download/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		bison cmake ssl python:3.9+ shebangfix tar:xz

SHEBANG_FILES=	src/ietf2bibtex

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${EXAMPLESDIR} -DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

OPTIONS_DEFINE=	EXAMPLES

# Remove trailing subdir from CMAKE_INSTALL_DOCDIR
post-patch:
	@${REINPLACE_CMD} -e 's|/examples||' ${WRKSRC}/src/CMakeLists.txt ${WRKSRC}/src/Images/CMakeLists.txt

.include <bsd.port.mk>
