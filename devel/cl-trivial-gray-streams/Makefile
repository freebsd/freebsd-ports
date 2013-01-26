# $FreeBSD$

PORTNAME=	trivial-gray-streams
PORTVERSION=	2008.11.02
PORTREVISION=	1
CATEGORIES=	devel lisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A thin compatibility layer for Gray streams

NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
