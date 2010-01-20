# New ports collection Makefile for:	cl-asdf-clisp
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	asdf
PORTVERSION=	1.374
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

# Even if this port builds FASL files, it is slightly different from
# other FASL ports because it uses USE_ASDF rather than USE_ASDF_FASL.

USE_ASDF=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

post-extract:
	@${MKDIR} ${WRKSRC}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
