# $FreeBSD$

PORTNAME=	alexandria
PORTVERSION=	2010.01.16
PORTREVISION=	3
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp

NO_BUILD=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/${PORTNAME}.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/alexandria.pdf ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
