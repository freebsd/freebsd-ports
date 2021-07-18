PORTNAME=	digital
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	cad java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital logic designer and circuit simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mvn:devel/maven

USES=		desktop-file-utils

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

ICON_SIZES=	32 48 64 128
ICON_NAME=	digital-logic-designer

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/Digital.jar \
		${ICON_SIZES:C/(.*)/share\/icons\/hicolor\/\1x\1\/apps\/${ICON_NAME}.png/} \
		share/icons/hicolor/scalable/apps/${ICON_NAME}.svg \
		share/applications/${PORTNAME}.desktop

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		-P no-git-rev -Dgit.commit.id.describe=${DISTVERSIONFULL} \
		package
do-install:
	# install jar
	${INSTALL_DATA} ${WRKSRC}/target/Digital.jar ${STAGEDIR}${JAVAJARDIR}
	# install shell wrapper
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${JAVA} -jar ${JAVAJARDIR}/Digital.jar \""$$"@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# install desktop file
	${SED} -e '\
		s|<EXEC_LOCATION>|${PREFIX}/bin/${PORTNAME}| ; \
		s|<ICON_LOCATION>|${ICON_NAME}|' \
		< ${WRKSRC}/distribution/linux/desktop.template \
		> ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	# install icons
.for SZ in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/src/main/resources/icons/icon${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/${ICON_NAME}.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/main/svg/icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${ICON_NAME}.svg

.include <bsd.port.mk>
