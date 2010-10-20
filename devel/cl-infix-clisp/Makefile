# New ports collection Makefile for:	cl-infix-clisp
# Date created:				20 Jan 2010
# Whom:					Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	infix
PORTVERSION=	19960628
PORTREVISION=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A lisp macro to read math statements in infix notation

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:${PORTSDIR}/devel/cl-infix
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/infix/infix.asd:${PORTSDIR}/devel/cl-infix

NO_CDROM=	No fees or compensation can be charged

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
