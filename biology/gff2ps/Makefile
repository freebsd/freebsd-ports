# New ports collection makefile for:	gff2ps
# Date created:				17 December 2001
# Whom:					Camson Huynh <chuynh@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	gff2ps
PORTVERSION=	0.97b
CATEGORIES=	biology
MASTER_SITES=	ftp://www1.imim.es/pub/gff_tools/gff2ps/
DISTNAME=	gff2ps_v${PORTVERSION}
EXTRACT_SUFX=	.gz

MAINTAINER=	chuynh@biolateral.com.au

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		bash:${PORTSDIR}/shells/bash2

PATCH_WRKSRC=	${WRKDIR}
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/gff2ps

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's,^#!/bin/bash,#!${LOCALBASE}/bin/bash,; \
		s,/usr/local/bin/gawk,${LOCALBASE}/bin/gawk,' ${WRKDIR}/gff2ps

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gff2ps ${PREFIX}/bin

.include <bsd.port.mk>
