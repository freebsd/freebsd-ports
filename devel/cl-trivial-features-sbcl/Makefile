PORTNAME=	trivial-features
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-4
PORTREVISION=	8
DISTVERSIONSUFFIX=	-gd249a62
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Ensures consistent *FEATURES* in Common Lisp
WWW=		https://www.cliki.net/trivial-features

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
