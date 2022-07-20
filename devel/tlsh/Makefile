PORTNAME=	tlsh
DISTVERSION=	4.7.2
CATEGORIES=	devel

MAINTAINER=	cgull@glup.org
COMMENT=	Trend Micro Locality Sensitive Hash library and utilities

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	trendmicro
GH_TAGNAME=	d842e75
USE_LDCONFIG=	yes

CMAKE_ARGS=	create_symlink \
		tlsh \
		tlsh_unittest
CMAKE_ON=	TLSH_SHARED_LIBRARY

PORTDOCS=	README.md TLSH_Introduction.pdf TLSH_CTC_final.pdf

# XXX Testing/test.sh is too dumb to work with separated source and
# build directories.
TEST_TARGET=	test

_TLSH_VERSION=	${PORTVERSION}
_SHLIBVERMAJ=	${DISTVERSION:S/./ /g:[1]}
PLIST_SUB=	SHLIBVER=${DISTVERSION} \
		SHLIBVERMAJ=${_SHLIBVERMAJ} \
		TLSH_VERSION=${_TLSH_VERSION}

OPTIONS_DEFINE=	DOCS
# The tlsh build always builds static libraries, and shared libraries
# are optional.  The STATIC option is the reverse, and can't be used
# with tlsh.
# OPTIONS_DEFINE=	STATIC
# OPTIONS_DEFAULT=
# STATIC_CMAKE_BOOL_OFF=	TLSH_SHARED_LIBRARY

post-build:
	${RLN} ${WRKSRC}/bin/tlsh_unittest ${WRKSRC}/bin/tlsh

# rely on cmake install for library itself, add docs and command after.
# XXX tlsh's install only installs ${INCLUDEDIR}/tlsh.h, and skips version.h,
# so we must install both in ${INCLUDEDIR}/tlsh/
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tlsh
	${RM} ${STAGEDIR}${PREFIX}/include/tlsh.h
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tlsh ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tlsh_unittest \
	    ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/include/tlsh.h \
	    ${STAGEDIR}${PREFIX}/include/tlsh/
	${INSTALL_DATA} ${WRKSRC}/include/version.h \
	    ${STAGEDIR}${PREFIX}/include/tlsh/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
