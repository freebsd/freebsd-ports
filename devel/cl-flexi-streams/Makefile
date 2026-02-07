PORTNAME=	flexi-streams
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.20
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Flexible bivalent streams for Common Lisp 
WWW=		http://edicl.github.io/flexi-streams/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams

USES=		cl
USE_GITHUB=	yes
GH_ACCOUNT=	edicl

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_PATHNAME}/test \
		${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/*.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/*.asd ${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/CHANGELOG \
		${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
