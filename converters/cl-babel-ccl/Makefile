PORTNAME=	babel
PORTVERSION=	2010.01.16
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp
WWW=		https://www.cliki.net/Babel

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/cclfasl/alexandria-1/arrays.fx64fsl:devel/cl-alexandria-ccl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/cclfasl/src/tf-openmcl.fx64fsl:devel/cl-trivial-features-ccl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/cclfasl/package.fx64fsl:devel/cl-trivial-gray-streams-ccl
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/cclfasl/alexandria-1/arrays.fx64fsl:devel/cl-alexandria-ccl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/cclfasl/src/tf-openmcl.fx64fsl:devel/cl-trivial-features-ccl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/cclfasl/package.fx64fsl:devel/cl-trivial-gray-streams-ccl

USES=		cl
ASDF_MODULES=	babel babel-streams
FASL_TARGET=	ccl

.include <bsd.port.mk>
