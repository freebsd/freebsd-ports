# Created by: trevor
# $FreeBSD$

PORTNAME=	festvox-el11
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	audio accessibility spanish
MASTER_SITES=	FESTIVAL/1.95
DISTNAME=	festvox_ellpc11k
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Castilian Spanish male voice for Festival

RUN_DEPENDS=	festival:audio/festival

WRKSRC=		${WRKDIR}/festival

CONFLICTS=	festvox-rab8

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	@${MKDIR} ${STAGEDIR}${FHOME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FHOME}
	${RM} -f ${STAGEDIR}${PREFIX}/share/festival/lib/voices/spanish/el_diphone/COPYING

.include <bsd.port.mk>
