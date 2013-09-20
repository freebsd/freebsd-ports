# $FreeBSD$

PORTNAME=	cffi
PORTVERSION=	0.11.0
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
COMMENT=	A portable foreign function interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:${PORTSDIR}/devel/cl-alexandria \
${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:${PORTSDIR}/converters/cl-babel
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:${PORTSDIR}/devel/cl-alexandria \
${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:${PORTSDIR}/converters/cl-babel

NO_BUILD=	yes

USE_ASDF=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_PATHNAME}/src
	@${MKDIR} ${ASDF_PATHNAME}/grovel
	@${MKDIR} ${ASDF_PATHNAME}/uffi-compat
	@${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/grovel/*.lisp ${ASDF_PATHNAME}/grovel
	@${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.asd ${ASDF_PATHNAME}/uffi-compat
	@${INSTALL_DATA} ${WRKSRC}/uffi-compat/*.lisp ${ASDF_PATHNAME}/uffi-compat
	@${INSTALL_DATA} ${WRKSRC}/cffi.asd ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/cffi-uffi-compat.asd ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/cffi-grovel.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for FILE in shareable-vectors.txt allegro-internals.txt mem-vector.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.html ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.txt ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-manual.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.html ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.txt ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cffi-sys-spec.pdf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/tests
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tests/* ${EXAMPLESDIR}/tests
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
