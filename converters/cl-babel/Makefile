PORTNAME=	babel
PORTVERSION=	2010.01.16
PORTREVISION=	2
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	LOCAL/olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams

NO_BUILD=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/babel.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/babel-streams.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/babel.asd ${ASDF_PATHNAME}/babel-streams.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in COPYRIGHT HEADER NOTES README
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tests/* ${STAGEDIR}${EXAMPLESDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
