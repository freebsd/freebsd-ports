# New ports collection makefile for:    ripit-atapi
# Version required:     1.5
# Date created:         9 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	ripit-1.5
PKGNAME=	ripit-atapi-1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.initio.no/~oyvindmo/distfiles/

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
