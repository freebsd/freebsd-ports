PORTNAME=	maven-wrapper
PORTVERSION=	2
CATEGORIES=	devel java
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	michaelo@apache.org
COMMENT=	Wrapper script for the various installations of Maven

NO_BUILD=	yes
SUB_FILES=	mvn.sh
SUB_LIST=	ETCDIR=${ETCDIR} CAT=${CAT} FIND=${FIND} TAIL=${TAIL}
PLIST_SUB=	ETCDIR=${ETCDIR}

do-install:
	${MKDIR} "${STAGEDIR}${ETCDIR}/instances.d"
	${INSTALL_SCRIPT} "${WRKDIR}/mvn.sh" "${STAGEDIR}${PREFIX}/bin/mvn"
	${INSTALL_SCRIPT} "${WRKDIR}/mvn.sh" "${STAGEDIR}${PREFIX}/bin/mvnDebug"

.include <bsd.port.mk>
