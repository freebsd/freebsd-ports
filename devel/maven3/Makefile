# New ports collection makefile for:	maven3
# Date created:		2011-08-24
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maven3
DISTVERSION=	3.0.3
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/binaries
DISTNAME=	apache-maven-${DISTVERSION}-bin

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java project management tool, 3.x branch

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/apache-maven-${DISTVERSION}
SUB_FILES=	mvn.sh
SUB_LIST=	CLASSWORLDS_JAR=plexus-classworlds-2.4.jar
.if !exists(${LOCALBASE}/bin/mvn)
PLIST_FILES+=	bin/mvn
.endif

post-extract:
	${RM} -f ${WRKSRC}/bin/*.bat

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -path "\./bin/" -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${DATADIR}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/mvn.sh ${DATADIR}/bin/mvn
.if !exists(${LOCALBASE}/bin/mvn)
	${LN} -fs ${DATADIR}/bin/mvn ${PREFIX}/bin/mvn
.endif

post-install:
	@${FIND} -s ${WRKSRC} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.mk>
