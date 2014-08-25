# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	2.5
CATEGORIES=	games
MASTER_SITES=	SF/ufoai/UFO_AI%202.x/${PORTVERSION}
PKGNAMEPREFIX=	ufoai-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}-${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	UFO alien invasion data files

# See http://ufoai.org/wiki/License
LICENSE=	GPLv2 CCbySA3
LICENSE_COMB=	multi
LICENSE_NAME_CCbySA3=	Creative Commons Attribution-ShareAlike 3.0 Unported
LICENSE_TEXT_CCbySA3=	See http://creativecommons.org/licenses/by-sa/3.0/
LICENSE_PERMS_CCbySA3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

EXTRACT_DEPENDS=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist

post-extract:
	@cd ${WRKDIR}/base && \
		${FIND} * -type f -exec ${UNZIP_CMD} "{}" -d ${WRKDIR}/base \;
	@${RM} ${WRKDIR}/base/*.pk3

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKDIR}/base && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/base/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/base/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%/base" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
	cd ${WRKDIR}/base && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${DATADIR}/base

.include <bsd.port.mk>
