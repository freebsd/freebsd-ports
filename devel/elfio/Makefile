PORTNAME=	elfio
PORTVERSION=	3.11
CATEGORIES=	devel
MASTER_SITES=	SF/elfio/ELFIO-sources/ELFIO-${PORTVERSION}

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Small C++ library for reading and generating ELF files
WWW=		http://elfio.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake ninja compiler:c++11-lang

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

EXAMPLES_CMAKE_BOOL=	ELFIO_BUILD_EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/elfio.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name *.txt")
	(cd ${BUILD_WRKSRC}/examples && \
	${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR} "-type f -perm -a=x")

.include <bsd.port.mk>
