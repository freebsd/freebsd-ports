PORTNAME=	flexi-streams
DISTVERSION=	1.0.20
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Flexible bivalent streams for Common Lisp
WWW=		http://edicl.github.io/flexi-streams/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fas:devel/cl-trivial-gray-streams-clisp
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fas:devel/cl-trivial-gray-streams-clisp

USES=		cl
FASL_TARGET=	clisp

.include <bsd.port.mk>
