PORTNAME=	flexi-streams
DISTVERSION=	1.0.20
PORTREVISION=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Flexible bivalent streams for Common Lisp
WWW=		http://edicl.github.io/flexi-streams/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
