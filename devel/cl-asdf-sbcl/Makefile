# New ports collection Makefile for:	cl-asdf-sbcl
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	asdf
PORTVERSION=	2003.05.16
CATEGORIES=	devel
MASTER_SITES=	http://www.henrik-motakef.de/freebsd-distfiles/asdf/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-sbcl
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf \
		sbcl:${PORTSDIR}/lang/sbcl

post-extract:
	${MKDIR} ${WRKSRC}

do-build:
	sbcl --noinform --userinit /dev/null --disable-debugger \
	     --eval '(compile-file "${PREFIX}/lib/common-lisp/asdf/asdf.lisp" \
				   :output-file "${WRKSRC}/asdf.fasl")' \
	     --eval '(compile-file "${PREFIX}/lib/common-lisp/asdf/wild-modules.lisp" \
				   :output-file "${WRKSRC}/wild-modules.fasl")' \
	     --eval '(quit)'

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/asdf/sbclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/asdf/sbclfasl

.include <bsd.port.mk>
