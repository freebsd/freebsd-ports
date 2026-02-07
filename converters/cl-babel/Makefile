PORTNAME=	babel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0-24
DISTVERSIONSUFFIX=	-g23c1440
PORTEPOCH=	1
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp
WWW=		https://babel.common-lisp.dev/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams

USES=		cl
USE_GITHUB=	yes
GH_ACCOUNT=	cl-babel

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/*.asd ${STAGEDIR}${ASDF_PATHNAME}/
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${ASDF_PATHNAME}/src)
	(cd ${WRKSRC}/tests && ${COPYTREE_SHARE} . ${STAGEDIR}${ASDF_PATHNAME}/tests)
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/*.asd ${STAGEDIR}${ASDF_REGISTRY}

.include <bsd.port.mk>
