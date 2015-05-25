# $FreeBSD$

PORTNAME=	cffi
PORTVERSION=	0.14.0
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable foreign function interface for Common Lisp

BUILD_DEPENDS=	cl-cffi>=0:${PORTSDIR}/devel/cl-cffi \
		cl-alexandria-sbcl>=0:${PORTSDIR}/devel/cl-alexandria-sbcl \
		cl-trivial-features-sbcl>=0:${PORTSDIR}/devel/cl-trivial-features-sbcl \
		cl-babel-sbcl>=0:${PORTSDIR}/converters/cl-babel-sbcl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes
ASDF_MODULES=	cffi cffi-grovel cffi-uffi-compat

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
