# New ports collection makefile for:	uffi
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$

PORTNAME=	uffi
PORTVERSION=	2.0.0
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	http://files.b9.com/uffi/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Universal Foreign Function Interface for Common Lisp

NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/uffi.asd   ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${ASDF_PATHNAME}/src
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
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

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
