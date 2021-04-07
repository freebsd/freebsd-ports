PORTNAME=	coronapoker
DISTVERSIONPREFIX=	v
DISTVERSION=	4.33
CATEGORIES=	games java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texas Holdem poker game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mvn:devel/maven

USE_JAVA=	11+
USE_GITHUB=	yes
GH_ACCOUNT=	tonikelope

NO_ARCH=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	JAVA=${JAVA} PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}-jar-with-dependencies.jar

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} .m2
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/yuri/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
MVN_ARGS=	--offline
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		JAVA_HOME=${JAVA_HOME} ${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		package

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/target/CoronaPoker-FINAL-*-jar-with-dependencies.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}-jar-with-dependencies.jar

.include <bsd.port.mk>
