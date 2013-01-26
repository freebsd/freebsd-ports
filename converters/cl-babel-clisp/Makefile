# $FreeBSD$

PORTNAME=	babel
PORTVERSION=	2010.01.16
PORTREVISION=	1
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A charset encoding/decoding library written in Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:${PORTSDIR}/converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fasl:${PORTSDIR}/devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fasl:${PORTSDIR}/devel/cl-trivial-gray-streams-clisp
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/babel/babel.asd:${PORTSDIR}/converters/cl-babel \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fasl:${PORTSDIR}/devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/clispfasl/package.fasl:${PORTSDIR}/devel/cl-trivial-gray-streams-clisp

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes
ASDF_MODULES=	babel babel-streams

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
