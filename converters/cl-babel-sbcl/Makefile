# $FreeBSD$

PORTNAME=	babel
PORTVERSION=	2010.01.16
PORTREVISION=	39
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Charset encoding/decoding library written in Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/arrays.fasl:devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/arrays.fasl:devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/sbclfasl/package.fasl:devel/cl-trivial-gray-streams-sbcl

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes
ASDF_MODULES=	babel babel-streams

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
