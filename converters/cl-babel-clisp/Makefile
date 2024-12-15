PORTNAME=	babel
PORTVERSION=	2010.01.16
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp
WWW=		https://www.cliki.net/Babel

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/alexandria-1/arrays.fas:devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fas:devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fas:devel/cl-trivial-gray-streams-clisp
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/alexandria-1/arrays.fas:devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fas:devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fas:devel/cl-trivial-gray-streams-clisp

USES=		cl
ASDF_MODULES=	babel babel-streams
FASL_TARGET=	clisp

.include <bsd.port.mk>
