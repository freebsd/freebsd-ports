# $FreeBSD$

PORTNAME=	alexandria
PORTVERSION=	2010.01.16
PORTREVISION=	44
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
