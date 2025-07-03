PORTNAME=	babel
DISTVERSION=	0.5.0-24
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp
WWW=		https://www.cliki.net/Babel

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/alexandria-1/arrays.fasl:devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/alexandria-1/arrays.fasl:devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl

USES=		cl
ASDF_MODULES=	babel babel-streams
FASL_TARGET=	sbcl

.include <bsd.port.mk>
