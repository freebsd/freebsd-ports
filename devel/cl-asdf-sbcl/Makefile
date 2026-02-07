PORTNAME=	asdf
PORTVERSION=	3.3.7
PORTREVISION=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	System definition facility for Common Lisp
WWW=		https://common-lisp.net/project/asdf/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:devel/cl-asdf
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:devel/cl-asdf

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
