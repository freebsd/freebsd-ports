PORTNAME=	metabase
DISTVERSIONPREFIX=	v
DISTVERSION=	0.41.5
CATEGORIES=	databases java
MASTER_SITES=	https://downloads.metabase.com/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	daniel@morante.net
COMMENT=	Simple and powerful analytics tool that supports multiple data stores

LICENSE=	AGPLv3

USES=		cpe

USE_JAVA=	yes
JAVA_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} \
		METABASEDATADIR=/var/db/${PORTNAME} \
		METABASE_USER=${USERS} \
		METABASE_GROUP=${GROUPS} \
		JAVA_HOME=${JAVA_HOME}

USERS=	www
GROUPS=	www

PLIST_FILES=	libexec/${PORTNAME}.jar "@sample etc/${PORTNAME}.conf.sample"

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.jar \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}.jar
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
