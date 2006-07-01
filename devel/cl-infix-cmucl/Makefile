# New ports collection Makefile for:	cl-infix-cmucl
# Date created: 			13 Feb 2006
# Whom: 				pfg
# $FreeBSD$

PORTNAME=	infix
DISTVERSION=	19960628
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/	\
		http://thingamy.com/cclan/	\
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-cmucl
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lisp macro for reading math expressions in infix form

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/infix/infix.asd:${PORTSDIR}/devel/cl-infix \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl

NO_CDROM=	No fees or compensation can be charged

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :infix)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/infix/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/infix/cmuclfasl/

.include <bsd.port.mk>
