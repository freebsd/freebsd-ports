# New ports collection makefile for:    hns
# Date created:                 10 Jun 1999
# Whom:                         Hyper NIKKI System Project <hnsmaster@h14m.org>
#
# $FreeBSD$
#

PORTNAME=	hns
PORTVERSION=	2.10.3
CATEGORIES=	japanese www perl5
MASTER_SITES=	http://www.h14m.org/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-pl${PORTVERSION:E}

MAINTAINER=	hnsmaster@h14m.org

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}-pl${PORTVERSION:E}

do-install:
	@if [ -d ${DATADIR} ]; then ${RM} -rf ${DATADIR}; fi
	${MKDIR} ${DATADIR}
	${CP} -pR ${WRKSRC}/ ${DATADIR}
	${CHOWN} -R 0:0 ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hns-setup ${PREFIX}/bin/hns-setup
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/todayhns/todayhns ${PREFIX}/bin/todayhns

post-install:
	@cd ${WRKSRC} && find . -type f -o -type l | sed 's,^\.,share/${PORTNAME},' | sort >> ${TMPPLIST}
	@cd ${WRKSRC} && find . -type d | sed 's,^\.,@dirrm share/${PORTNAME},' | sort -r >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
