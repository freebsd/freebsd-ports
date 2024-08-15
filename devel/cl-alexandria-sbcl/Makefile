PORTNAME=	alexandria
PORTVERSION=	1.2
PORTREVISION=	35
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

LICENSE=	PD

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp
WWW=		https://common-lisp.net/project/alexandria/

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
