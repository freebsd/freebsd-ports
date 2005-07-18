# New ports collection makefile for:	maven2
# Date created:				18 August 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maven2
DISTVERSION=	2.0-alpha-3
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/binaries
DISTNAME=	maven-${DISTVERSION}-bin

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java project management tool, 2.0 branch

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	m2.sh
WRKSRC=		${WRKDIR}/maven-${DISTVERSION}

post-extract:
	${RM} -f ${WRKSRC}/bin/m2.bat

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -name "m2" -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/m2.sh ${DATADIR}/bin/m2
	${LN} -fs ${DATADIR}/bin/m2 ${PREFIX}/bin/m2

post-install:
	@${ECHO_CMD} 'bin/m2' >> ${TMPPLIST}
	@${FIND} -s ${WRKSRC} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.mk>
