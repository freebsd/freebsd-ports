PORTNAME=	cffi
PORTVERSION=	0.16.1
CATEGORIES=	devel lisp
MASTER_SITES=	http://common-lisp.net/project/cffi/releases/:src \
		http://olgeni.olgeni.com/~olgeni/cffi/${PORTVERSION}/:doc
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}_${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		cffi-manual.html:doc \
		cffi-manual.txt:doc \
		cffi-manual.pdf:doc \
		cffi-sys-spec.html:doc \
		cffi-sys-spec.txt:doc \
		cffi-sys-spec.pdf:doc
DIST_SUBDIR=	cffi/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable foreign function interface for Common Lisp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	cl-alexandria>=0:devel/cl-alexandria \
		cl-trivial-features>=0:devel/cl-trivial-features \
		cl-babel>=0:converters/cl-babel
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/src
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/grovel
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/uffi-compat
	@${MKDIR} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/src
	${INSTALL_DATA} ${WRKSRC}/grovel/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/grovel
	${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.asd ${STAGEDIR}${ASDF_PATHNAME}/uffi-compat
	${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/uffi-compat
	${INSTALL_DATA} ${WRKSRC}/cffi.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cffi-uffi-compat.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cffi-grovel.asd ${STAGEDIR}${ASDF_PATHNAME}
	${LN} -sf ${ASDF_PATHNAME}/cffi.asd ${ASDF_PATHNAME}/cffi-uffi-compat.asd \
		${ASDF_PATHNAME}/cffi-grovel.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.for FILE in shareable-vectors.txt allegro-internals.txt mem-vector.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.pdf ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/tests
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/* ${STAGEDIR}${EXAMPLESDIR}/tests

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
