# New ports collection makefile for:	uffi
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$
#

PORTNAME=	uffi
PORTVERSION=	1.5.17
CATEGORIES=	devel lisp
MASTER_SITES=	http://files.b9.com/uffi/
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Universal Foreign Function Interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=	yes
CL_LIBDIR?=	${LOCALBASE}/lib/common-lisp

do-install:
	@${MKDIR} ${CL_LIBDIR}/uffi
	@${MKDIR} ${CL_LIBDIR}/uffi/src
	@${INSTALL_DATA} ${WRKSRC}/uffi.asd   ${CL_LIBDIR}/uffi/
	@${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${CL_LIBDIR}/uffi/src/
	@${LN} -sf ${CL_LIBDIR}/uffi/uffi.asd ${CL_LIBDIR}/system-registry/uffi.asd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${DOCSDIR} -xf ${WRKSRC}/doc/html.tar.gz
	@${CHOWN} ${DOCOWN}:${DOCGRP} ${DOCSDIR}/html/*
	@${CHMOD} ${DOCMODE}  ${DOCSDIR}/html/*
	@${INSTALL_DATA} ${WRKSRC}/doc/uffi.pdf ${DOCSDIR}
.for FILE in AUTHORS ChangeLog INSTALL LICENSE NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
