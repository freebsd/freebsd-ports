PORTNAME=	split-sequence
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-3
PORTREVISION=	8
DISTVERSIONSUFFIX=	-g89a10b4
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Partitioning Common Lisp sequences
WWW=		https://www.cliki.net/SPLIT-SEQUENCE

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/split-sequence/split-sequence.asd:devel/cl-split-sequence
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/split-sequence/split-sequence.asd:devel/cl-split-sequence

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
