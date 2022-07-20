PORTNAME=	maven-wrapper
PORTVERSION=	1
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper script for the various installations of Maven

NO_BUILD=	yes
SUB_FILES=	mvn.sh
SUB_LIST=	CAT=${CAT} FIND=${FIND} TAIL=${TAIL}

do-install:
	${MKDIR} "${STAGEDIR}${PREFIX}/etc/maven-wrapper/instances.d"
	${INSTALL_SCRIPT} "${WRKDIR}/mvn.sh" "${STAGEDIR}${PREFIX}/bin/mvn"

.include <bsd.port.mk>
