# $FreeBSD$

PORTNAME=	cffi
PORTVERSION=	0.10.6
PORTREVISION=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A portable foreign function interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cffi/cffi.asd:${PORTSDIR}/devel/cl-cffi \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fasl:${PORTSDIR}/devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/clispfasl/src/enc-ascii.fasl:${PORTSDIR}/converters/cl-babel-clisp
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cffi/cffi.asd:${PORTSDIR}/devel/cl-cffi \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/clispfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/clispfasl/src/tf-clisp.fasl:${PORTSDIR}/devel/cl-trivial-features-clisp \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/clispfasl/src/enc-ascii.fasl:${PORTSDIR}/converters/cl-babel-clisp

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes
ASDF_MODULES=	cffi cffi-grovel cffi-uffi-compat

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
