PORTNAME=	elfio
DISTVERSIONPREFIX=	Release_
DISTVERSION=	3.12-102
DISTVERSIONSUFFIX=	-g7d30a22 # use latest commit hash because the last release was 2 years ago
CATEGORIES=	devel

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Small C++ library for reading and generating ELF files
WWW=		https://elfio.sourceforge.net/ \
		https://github.com/serge1/ELFIO

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	serge1
GH_PROJECT=	ELFIO

CMAKE_OFF=	ELFIO_BUILD_EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

#EXAMPLES_CMAKE_BOOL=	ELFIO_BUILD_EXAMPLES # do not build examples to keep this port NOARCH (absolute majority of users will not need them)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/elfio.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	# install example sources
	cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name *.txt"
	# do not install example binaries, just the sources
	#(cd ${BUILD_WRKSRC}/examples && \
		${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR} "-type f -perm -a=x")

.include <bsd.port.mk>
