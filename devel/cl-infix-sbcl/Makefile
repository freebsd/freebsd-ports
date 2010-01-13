# New ports collection Makefile for:	cl-infix-sbcl
# Date created:				13 Feb 2006
# Whom:					Pedro F Giffuni
#
# $FreeBSD$

PORTNAME=	infix
DISTVERSION=	19960628
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://thingamy.com/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-sbcl
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A lisp macro to read math statements in infix notation

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/infix/infix.asd:${PORTSDIR}/devel/cl-infix \
		sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		sbcl:${PORTSDIR}/lang/sbcl

NO_CDROM=	No fees or compensation can be charged

do-build:
	@FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	sbcl	--noinform --userinit /dev/null \
		--eval '#.(load "${LOCALBASE}/etc/asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :infix)" \
		--eval "(quit)"

do-install:
	@${MKDIR} ${PREFIX}/lib/common-lisp/infix/sbclfasl
	@${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/infix/sbclfasl/

.include <bsd.port.mk>
