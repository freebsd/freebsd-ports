# New ports collection Makefile for:	cl-uffi-cmucl
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$

PORTNAME=	uffi
PORTVERSION=	1.4.37
CATEGORIES=	devel
MASTER_SITES=	http://files.b9.com/uffi/
PKGNAMEPREFIX=	cl-
PKGNAMESUFFIX=	-cmucl
DISTFILES=	# use installed sources from CL_LIBDIR
EXTRACT_ONLY=	# use installed sources from CL_LIBDIR

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Universal Foreign Function Interface for Common Lisp (CMU CL binaries)

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/uffi/uffi.asd:${PORTSDIR}/devel/cl-uffi \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/port/port.asd:${PORTSDIR}/devel/cl-port \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :uffi)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/uffi/src/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/uffi/src/cmuclfasl/

.include <bsd.port.mk>
