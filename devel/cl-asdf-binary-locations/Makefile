# New ports collection makefile for:	cl-asdf-binary-locations
# Date created:				18 January 2010
# Whom:					Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	asdf-binary-locations
PORTVERSION=	0.3.9
PORTREVISION=	2
CATEGORIES=	devel lisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Selects where your Common Lisp binaries (FASL files) should go

NO_BUILD=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_PATHNAME}/dev
	@${INSTALL_DATA} ${WRKSRC}/dev/*.lisp ${ASDF_PATHNAME}/dev
	@${INSTALL_DATA} ${WRKSRC}/asdf-binary-locations.asd ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_REGISTRY}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
