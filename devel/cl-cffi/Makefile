PORTNAME=	cffi
PORTVERSION=	0.24.1
CATEGORIES=	devel lisp
MASTER_SITES=	http://common-lisp.net/project/cffi/releases/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable foreign function interface for Common Lisp
WWW=		https://common-lisp.net/project/cffi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	cl-alexandria>=0:devel/cl-alexandria \
		cl-babel>=0:converters/cl-babel \
		cl-trivial-features>=0:devel/cl-trivial-features
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cl
USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES PDF

PDF_DESC=	Build and install PDF documentation

DOCS_USES=	makeinfo

PDF_IMPLIES=		DOCS
PDF_BUILD_DEPENDS=	texi2pdf:print/texinfo
PDF_USES=		tex
PDF_USE=		TEX=dvipdfmx:build
PDF_PLIST_FILES=	${DOCSDIR}/cffi-manual.pdf \
			${DOCSDIR}/cffi-sys-spec.pdf

DOCUMENTS=	cffi-manual cffi-sys-spec

do-build:
	@${DO_NADA}

do-build-DOCS-on:
.for FILE in ${DOCUMENTS}
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKEINFO} \
		--html --no-split --css-include=style.css \
		-o ${FILE}.html ${FILE}.texinfo
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKEINFO} \
		--plaintext -o ${FILE}.txt ${FILE}.texinfo
.endfor

do-build-PDF-on:
.for FILE in ${DOCUMENTS}
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} texi2pdf -q -o ${FILE}.pdf ${FILE}.texinfo
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/src/c2ffi \
		${STAGEDIR}${ASDF_PATHNAME}/grovel \
		${STAGEDIR}${ASDF_PATHNAME}/toolchain \
		${STAGEDIR}${ASDF_PATHNAME}/uffi-compat \
		${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/src
	${INSTALL_DATA} ${WRKSRC}/src/c2ffi/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/src/c2ffi
	${INSTALL_DATA} ${WRKSRC}/grovel/*.lisp ${WRKSRC}/grovel/common.h \
		${STAGEDIR}${ASDF_PATHNAME}/grovel
	${INSTALL_DATA} ${WRKSRC}/toolchain/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/toolchain
	${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.asd ${STAGEDIR}${ASDF_PATHNAME}/uffi-compat
	${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/uffi-compat
	${INSTALL_DATA} ${WRKSRC}/cffi.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cffi-uffi-compat.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cffi-grovel.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cffi-toolchain.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/cffi.asd \
		${STAGEDIR}${ASDF_PATHNAME}/cffi-uffi-compat.asd \
		${STAGEDIR}${ASDF_PATHNAME}/cffi-grovel.asd \
		${STAGEDIR}${ASDF_PATHNAME}/cffi-toolchain.asd \
		${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.for FILE in allegro-internals.txt mem-vector.txt shareable-vectors.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOCUMENTS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.html ${WRKSRC}/doc/${FILE}.txt \
		${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/tests
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/* ${STAGEDIR}${EXAMPLESDIR}/tests

do-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCUMENTS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.pdf ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
