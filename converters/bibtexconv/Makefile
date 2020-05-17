# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	bibtexconv
PORTVERSION=	1.1.20
CATEGORIES=	converters
MASTER_SITES=	https://www.uni-due.de/~be0001/bibtexconv/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	BibTeX Converter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		bison cmake ssl python:3.4+ shebangfix tar:xz

SHEBANG_FILES=	src/ietf2bibtex

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${EXAMPLESDIR} -DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

OPTIONS_DEFINE=	EXAMPLES

# Remove trailing subdir from CMAKE_INSTALL_DOCDIR
post-patch:
	@${REINPLACE_CMD} -e 's|/examples||' ${WRKSRC}/src/CMakeLists.txt ${WRKSRC}/src/Images/CMakeLists.txt

.include <bsd.port.mk>
