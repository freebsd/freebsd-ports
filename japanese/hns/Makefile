# Created by: Hyper NIKKI System Project <hnsmaster@h14m.org>
# $FreeBSD$

PORTNAME=	hns
PORTVERSION=	2.19.9
CATEGORIES=	japanese www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	h14m/22597

MAINTAINER=	hnsmaster@h14m.org
COMMENT=	Hyper NIKKI System, a CGI system for Electric Diary Interchange

USES=		perl5
NO_BUILD=	yes

do-install:
	@if [ -d ${DATADIR} ]; then ${RM} -rf ${DATADIR}; fi
	${MKDIR} ${DATADIR}
	${CP} -pR ${WRKSRC}/ ${DATADIR}
	${CHOWN} -R 0:0 ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hns-setup ${PREFIX}/bin/hns-setup
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/todayhns/todayhns ${PREFIX}/bin/todayhns

post-install:
	@cd ${WRKSRC} && ${FIND} . -type f -o -type l | \
		${SED} 's,^\.,share/${PORTNAME},' | ${SORT} >> ${TMPPLIST}
	@cd ${WRKSRC} && ${FIND} . -type d | \
		${SED} 's,^\.,@dirrm share/${PORTNAME},' | ${SORT} -r \
			>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
