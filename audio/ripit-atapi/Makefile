# New ports collection makefile for:    ripit-atapi
# Date created:         9 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	ripit-atapi
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.initio.no/~oyvindmo/distfiles/
DISTNAME=	ripit-1.5

MAINTAINER=	dburr@FreeBSD.ORG

RUN_DEPENDS=	bladeenc:${PORTSDIR}/audio/bladeenc \
		cdd:${PORTSDIR}/audio/cdd \
		cda:${PORTSDIR}/audio/xmcd \
		sox:${PORTSDIR}/audio/sox

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin

.include <bsd.port.mk>
