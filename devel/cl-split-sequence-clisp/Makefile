# New ports collection Makefile for:	cl-split-sequence-clisp
# Date created:				12 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		split-sequence
PORTVERSION=		20011114.1
PORTREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-clisp
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		henrik.motakef@web.de
COMMENT=		Partinitoning Common Lisp sequences

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/split-sequence/split-sequence.asd:${PORTSDIR}/devel/cl-split-sequence \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/split-sequence/split-sequence.asd:${PORTSDIR}/devel/cl-split-sequence \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp

do-build:
	FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	clisp	-q -ansi -norc \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :split-sequence)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/split-sequence/clispfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/split-sequence/clispfasl/

.include <bsd.port.mk>
