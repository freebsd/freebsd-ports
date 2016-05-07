# Created by: Mikhail T. <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	atlassian-plugin-sdk
PORTVERSION=	6.0.1
CATEGORIES=	devel java
MASTER_SITES=	https://maven.atlassian.com/content/repositories/atlassian-public/com/atlassian/amps/atlassian-plugin-sdk/${PORTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Atlassian Plugin SDK

RUN_DEPENDS=	mvn:devel/maven-wrapper

USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_ARCH=	yes

EXTRACT_AFTER_ARGS=${DISTNAME}/bin ${DISTNAME}/apache-maven*/conf/settings.xml

NO_BUILD=	Just sh-scripts and JARs here, no source code
MAVEN_SETTINGS=	${ETCDIR_REL}/settings.xml
PLIST_SUB+=	MAVEN_SETTINGS="${MAVEN_SETTINGS}"
RESTRICTED=	License uncertain and no point in redistributing anyway

post-patch:
	${REINPLACE_CMD} -i ""	\
		-e '$$s,^sh -c "\([^"]*\)",exec \1,'	\
		-e 's|^ATLAS_HOME=.*|ATLAS_HOME=${DATADIR}|'	\
		-e 's|^MAVEN_EXECUTABLE=.*|MAVEN_EXECUTABLE=${LOCALBASE}/bin/mvn|'	\
		-e '/^M2_HOME/d'	\
		-e 's/^read$$/& unused/'	\
		-e 's|^MVN_PARAMS=.*|MVN_PARAMS="-gs ${PREFIX}/${MAVEN_SETTINGS}"|' \
		-e 's|\$${ATLAS_HOME}/bin|${PREFIX}/bin|g'	\
		${WRKSRC}/bin/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/${MAVEN_SETTINGS:H}
	${INSTALL_DATA} ${WRKSRC}/apache-maven*/conf/settings.xml	\
		${STAGEDIR}${PREFIX}/${MAVEN_SETTINGS}.dist
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} --strip-components 1 -C ${STAGEDIR}${DATADIR} -xv	\
	    --no-same-permissions --no-same-owner --exclude maven	\
	    -f ${DISTDIR}/${DISTFILES} ${DISTNAME}/repository 2>&1 | \
		${SED} -e 's,^x ,${DATADIR_REL}/,' -e 's,.*/$$,@dir &,' | \
		${SORT} -r >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/repository -type f | ${XARGS} ${CHMOD} ${_SHAREMODE}

.include <bsd.port.mk>
