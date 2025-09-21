PORTNAME=	traccar
PORTVERSION=	6.10.0
CATEGORIES=	astro java
MASTER_SITES=	https://github.com/traccar/traccar/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-other-${DISTVERSION}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Traccar is a free and open source GPS tracking system
WWW=		https://www.traccar.org/

LICENSE=	APACHE20

USES=		zip java
JAVA_VERSION=	17+
USE_RC_SUBR=	traccar

USERS=		traccar
GROUPS=		traccar

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

TRACCAR_HOME=		${PREFIX}/${PORTNAME}
TRACCAR_DATADIR?=	/var/db/${PORTNAME}
TRACCAR_LOGDIR?=	/var/log/${PORTNAME}

PLIST_SUB=	TRACCAR_DATADIR=${TRACCAR_DATADIR} \
		TRACCAR_LOGDIR=${TRACCAR_LOGDIR}
SUB_LIST=	TRACCAR_DATADIR=${TRACCAR_DATADIR} \
		TRACCAR_LOGDIR=${TRACCAR_LOGDIR}
SUB_FILES=	traccar.xml pkg-message

do-install:
		${MKDIR} ${STAGEDIR}${TRACCAR_HOME} \
		    ${STAGEDIR}${TRACCAR_DATADIR} \
		    ${STAGEDIR}${TRACCAR_LOGDIR} \
		    ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKDIR}/traccar.xml \
		    ${STAGEDIR}${ETCDIR}/traccar.xml.sample
		${INSTALL_DATA} ${WRKSRC}/tracker-server.jar ${STAGEDIR}${TRACCAR_HOME}
.for i in lib schema templates web
		(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${TRACCAR_HOME})
.endfor

.include <bsd.port.mk>
