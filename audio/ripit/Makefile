# New ports collection makefile for:    ripit
# Version required:     1.2
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $Id$
#

DISTNAME=	ripit-1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.netcomuk.co.uk/~squinn/

MAINTAINER=	oyvindmo@initio.no

RUN_DEPENDS=	bladeenc:${PORTSDIR}/audio/bladeenc \
		tosha:${PORTSDIR}/audio/tosha \
		cda:${PORTSDIR}/audio/xmcd

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin

.include <bsd.port.mk>
