# $FreeBSD$

PORTNAME=	lizzie
DISTVERSION=	0.6-105
DISTVERSIONSUFFIX=	-gd0e7040
CATEGORIES=	games java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Leela Zero Interface: GUI for the Go game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mvn:devel/maven
RUN_DEPENDS=	leelaz:games/leela-zero

USE_JAVA=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	featurecat

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

DESKTOP_ENTRIES=	"SGF Editor (Go)" "A GUI for Leela-Zero" "" "${PORTNAME}" "Game;" ""

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/lizzie-${PORTVERSION:R}-shaded.jar

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		package
do-install:
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION:R}-shaded.jar ${STAGEDIR}${JAVAJARDIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "mkdir -p ~/.local/share/lizzie &&"; \
	  echo "cd ~/.local/share/lizzie && ${JAVA} -jar ${JAVAJARDIR}/${PORTNAME}-${PORTVERSION:R}-shaded.jar \""$$"@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
