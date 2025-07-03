PORTNAME=	port
PORTVERSION=	2002.10.02.1
PORTREVISION=	100
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cross-Lisp portability package
WWW=		https://clocc.sourceforge.net

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:devel/cl-port
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:devel/cl-port

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
