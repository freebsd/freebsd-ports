# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	20100630
CATEGORIES=	games
MASTER_SITES=	SF/vdrift/vdrift/vdrift-${DATE_VERSION}
PKGNAMEPREFIX=	vdrift-
DISTNAME=	${PKGNAMEPREFIX}${DATE_VERSION}
DIST_SUBDIR=	vdrift

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Vdrift driving simulation data files

LICENSE=	GPLv2

USE_BZIP2=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/vdrift
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${DATE_VERSION}

DATE_VERSION=	2010-06-30

post-extract:
	@cd ${WRKSRC}/data && \
		${FIND} * -name "SConscript*" -print0 | ${XARGS} -0 ${RM}
.for DIRE in music
	@${RMDIR} ${WRKSRC}/data/${DIRE}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
