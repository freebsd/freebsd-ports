PORTNAME=	trivial-gray-streams
PORTVERSION=	20240217
PORTREVISION=	7
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Thin compatibility layer for Gray streams
WWW=		https://www.cliki.net/trivial-gray-streams

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:devel/cl-trivial-gray-streams

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
