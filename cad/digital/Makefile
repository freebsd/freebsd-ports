# $FreeBSD$

PORTNAME=	digital
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24
CATEGORIES=	cad java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital logic designer and circuit simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mvn:devel/maven

USE_JAVA=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	hneemann
GH_PROJECT=	Digital

NO_ARCH=	yes

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
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/yuri/:maven
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MVN_ARGS=	--offline
.endif

DESKTOP_ENTRIES=	"Digital logic designer" "Digital logic designer and circuit simulator" "" "${PORTNAME}" "Electronics;" ""

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/Digital.jar

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		-P no-git-rev -Dgit.commit.id.describe=${DISTVERSIONFULL} \
		package
do-install:
	${INSTALL_DATA} ${WRKSRC}/target/Digital.jar ${STAGEDIR}${JAVAJARDIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${JAVA} -jar ${JAVAJARDIR}/Digital.jar \""$$"@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
