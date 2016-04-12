# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	festvox
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	SF/festlang.berlios/ \
		BERLIOS/festlang
PKGNAMESUFFIX=	-russian
DISTNAME=	msu_ru_nsh_clunits-${PORTVERSION}
DIST_SUBDIR=	festival

MAINTAINER=	yerenkow@gmail.com
COMMENT=	Russian male voice for Festival speech synthesis system

RUN_DEPENDS=	festival:audio/festival

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/msu_ru_nsh_clunits

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival/lib/voices/russian/msu_ru_nsh_clunits

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	@${MKDIR} ${STAGEDIR}${FHOME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FHOME})

.include <bsd.port.mk>
