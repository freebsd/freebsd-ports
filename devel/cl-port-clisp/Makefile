# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	port
PORTVERSION=	2002.10.02.1
PORTREVISION=	5
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cross-Lisp portability package

DEPRECATED=	Depends on deprecated lang/clisp
EXIPIRATION_DATE=	2014-07-28

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:${PORTSDIR}/devel/cl-port
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:${PORTSDIR}/devel/cl-port

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
