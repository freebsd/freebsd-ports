PORTNAME=	alexandria
PORTVERSION=	1.4
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp
WWW=		https://common-lisp.net/project/alexandria/

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
