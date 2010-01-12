# New ports collection Makefile for:	cl-port-clisp
# Date created:				12 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	port
PORTVERSION=	2002.10.02.1
PORTREVISION=	2
CATEGORIES=	devel lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-clisp
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cross-Lisp portability package

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
		clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
		clisp:${PORTSDIR}/lang/clisp

do-build:
	@FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	clisp	-q -ansi -norc \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :port)"

do-install:
	@${MKDIR} ${PREFIX}/lib/common-lisp/port/clispfasl
	@${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/port/clispfasl/

.include <bsd.port.mk>
