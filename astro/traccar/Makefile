PORTNAME=	traccar
PORTVERSION=	6.11.1
CATEGORIES=	astro java
MASTER_SITES=	https://github.com/traccar/traccar/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-other-${DISTVERSION}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Traccar is a free and open source GPS tracking system
WWW=		https://www.traccar.org/

LICENSE=	APACHE20

USES=		java zip
JAVA_VERSION=	17+
USE_RC_SUBR=	traccar

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message traccar.xml
SUB_LIST=	TRACCAR_DATADIR=${TRACCAR_DATADIR} \
		TRACCAR_LOGDIR=${TRACCAR_LOGDIR}

NO_WRKSUBDIR=	yes

USERS=		traccar
GROUPS=		traccar

TRACCAR_HOME=		${PREFIX}/${PORTNAME}
TRACCAR_DATADIR?=	/var/db/${PORTNAME}
TRACCAR_LOGDIR?=	/var/log/${PORTNAME}

PLIST_SUB=	TRACCAR_DATADIR=${TRACCAR_DATADIR} \
		TRACCAR_LOGDIR=${TRACCAR_LOGDIR}

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
