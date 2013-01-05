# Created by: Jimmy Olgeni <olgeni@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cffi
PORTVERSION=	0.10.6
PORTREVISION=	7
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A portable foreign function interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cffi/cffi.asd:${PORTSDIR}/devel/cl-cffi \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:${PORTSDIR}/devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/sbclfasl/src/enc-ascii.fasl:${PORTSDIR}/converters/cl-babel-sbcl
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cffi/cffi.asd:${PORTSDIR}/devel/cl-cffi \
		${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/sbclfasl/arrays.fasl:${PORTSDIR}/devel/cl-alexandria-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/sbclfasl/src/tf-sbcl.fasl:${PORTSDIR}/devel/cl-trivial-features-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/babel/sbclfasl/src/enc-ascii.fasl:${PORTSDIR}/converters/cl-babel-sbcl

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes
ASDF_MODULES=	cffi cffi-grovel cffi-uffi-compat

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
