# New ports collection Makefile for:	cl-asdf-sbcl
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	asdf
PORTVERSION=	1.374
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-clisp
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		clisp:${PORTSDIR}/lang/clisp

ASDF_MODULES=	asdf.lisp wild-modules.lisp

post-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	@for FILE in ${ASDF_MODULES}; do \
		clisp -q -ansi -norc \
			-x "(compile-file \"${LOCALBASE}/lib/common-lisp/asdf/$${FILE}\" :output-file \"${WRKSRC}/$$(${BASENAME} $${FILE} .lisp).fasl\")" \
			-x "(quit)"; \
	done

do-install:
	@${MKDIR} ${PREFIX}/lib/common-lisp/asdf/clispfasl
	@${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/asdf/clispfasl

.include <bsd.port.mk>
