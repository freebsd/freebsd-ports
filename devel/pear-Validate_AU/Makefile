# Ports collection makefile for:  pear-Validate_AU
# Date created:			  26 Jan 2008
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Validate_AU
PORTVERSION=	0.1.3
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR data validation class for Australia

BUILD_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate

FILES=		Validate/AU.php Validate/data/AU_postcodes.txt
TESTS=		validate_AU.phpt

post-extract:
	${MV} ${WRKSRC}/data ${WRKSRC}/Validate/
	${REINPLACE_CMD} 's|Validate_AU/data|Validate/data|g' ${WRKSRC}/Validate/AU.php
	${REINPLACE_CMD} 's|\@DATADIR\@|${PEARDIR}|g' ${WRKSRC}/Validate/AU.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
