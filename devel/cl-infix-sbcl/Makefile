# Created by: Pedro F Giffuni

PORTNAME=	infix
PORTVERSION=	19960628
PORTREVISION=	68
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp macro to read math statements in infix notation

# Converted from NO_CDROM
LICENSE=	infix
LICENSE_NAME=	infix
LICENSE_TEXT=	No fees or compensation can be charged
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:devel/cl-infix
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:devel/cl-infix

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
