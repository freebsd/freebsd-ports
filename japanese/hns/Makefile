# New ports collection makefile for:    hns
# Version required:             2.00-pl3
# Date created:                 10 Jun 1999
# Whom:                         Hyper NIKKI System Project <hnsmaster@h14m.org>
#
# $FreeBSD$
#

DISTNAME=	hns-2.00-pl3
PKGNAME=	ja-hns-2.00.3
CATEGORIES=	japanese www perl5
MASTER_SITES=	http://www.h14m.org/dist/

MAINTAINER=	hnsmaster@h14m.org

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/hns-2.00

do-install:
	${MKDIR} ${PREFIX}/share/hns
	${CP} -pR ${WRKSRC}/ ${PREFIX}/share/hns
	${INSTALL_SCRIPT} ${WRKDIR}/hns-setup ${PREFIX}/bin/hns-setup
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/todayhns/todayhns ${PREFIX}/bin/todayhns

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
