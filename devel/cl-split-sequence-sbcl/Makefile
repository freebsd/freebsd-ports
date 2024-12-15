PORTNAME=	split-sequence
PORTVERSION=	20011114.1
PORTREVISION=	92
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
