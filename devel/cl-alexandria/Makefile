# $FreeBSD$

PORTNAME=	alexandria
PORTVERSION=	2010.01.16
PORTREVISION=	2
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A collection of portable public domain utilities for Common Lisp

NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/alexandria.pdf ${DOCSDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
