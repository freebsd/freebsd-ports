# New ports collection Makefile for:	cl-split-sequence-cmucl
# Date created:				12. May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		split-sequence
PORTVERSION=		20011114.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-cmucl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Partinitoning Common Lisp sequences

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/split-sequence/split-sequence.asd:${PORTSDIR}/devel/cl-split-sequence \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/split-sequence/split-sequence.asd:${PORTSDIR}/devel/cl-split-sequence \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :split-sequence)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/split-sequence/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/split-sequence/cmuclfasl/

.include <bsd.port.mk>
