# New ports collection makefile for:    mencal
# Date created:                 17 April 2002
# Whom:                         Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	mencal
PORTVERSION=	2.1
CATEGORIES=	deskutils
MASTER_SITES=	http://mencal.kyberdigi.cz/ \
		http://unixpages.org/distfiles/

MAINTAINER=	chris@unixpages.org

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencal ${PREFIX}/bin

.include <bsd.port.mk>
