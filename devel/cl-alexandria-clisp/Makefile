PORTNAME=	alexandria
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp
WWW=		https://common-lisp.net/project/alexandria/

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:devel/cl-alexandria

USES=		cl
FASL_TARGET=	clisp
LISP_EXTRA_ARG=	-E UTF-8

.include <bsd.port.mk>
