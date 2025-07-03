PORTNAME=	infix
PORTVERSION=	19960628
PORTREVISION=	102
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp macro to read math statements in infix notation
WWW=		https://www.cliki.net/infix

# Converted from NO_CDROM
LICENSE=	infix
LICENSE_NAME=	infix
LICENSE_TEXT=	No fees or compensation can be charged
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:devel/cl-infix
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:devel/cl-infix

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
