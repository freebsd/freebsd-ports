# New ports collection Makefile for:	cl-uffi-sbcl
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$

PORTNAME=	uffi
PORTVERSION=	1.6.2
CATEGORIES=	devel lisp
MASTER_SITES=	# use installed sources from CL_LIBDIR
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-sbcl
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Universal Foreign Function Interface for Common Lisp (SBCL binaries)

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/uffi/uffi.asd:${PORTSDIR}/devel/cl-uffi \
		sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		sbcl:${PORTSDIR}/lang/sbcl

CL_LIBDIR?=	${LOCALBASE}/lib/common-lisp

do-build:
	@FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	sbcl	--noinform --userinit /dev/null --disable-debugger \
		--eval '#.(load "${LOCALBASE}/etc/asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :uffi)" \
		--eval "(quit)"

do-install:
	@${MKDIR} ${CL_LIBDIR}/uffi/src/sbclfasl
	@${INSTALL_DATA} ${WRKSRC}/*.fasl ${CL_LIBDIR}/uffi/src/sbclfasl/

.include <bsd.port.mk>
