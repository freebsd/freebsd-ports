# New ports collection Makefile for:	cl-asdf-sbcl
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	asdf
PORTVERSION=	2003.05.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.henrik-motakef.de/freebsd-distfiles/asdf/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-clisp
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		clisp:${PORTSDIR}/lang/clisp

post-extract:
	${MKDIR} ${WRKSRC}

do-build:
	clisp -q -ansi -norc \
		-c ${PREFIX}/lib/common-lisp/asdf/asdf.lisp -o ${WRKSRC}/asdf.fasl \
		-c ${PREFIX}/lib/common-lisp/asdf/wild-modules.lisp -o ${WRKSRC}/wild-modules.fasl

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/asdf/clispfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/asdf/clispfasl

.include <bsd.port.mk>
