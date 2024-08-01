PORTNAME=	ghidra
DISTVERSION=	11.1.2
CATEGORIES=	devel security java
MASTER_SITES=	https://github.com/NationalSecurityAgency/${PORTNAME}/releases/download/Ghidra_${DISTVERSION}_build/
DISTNAME=	${PORTNAME}_${DISTVERSION}_PUBLIC_20240709

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Software reverse engineering (SRE) framework
WWW=		https://ghidra-sre.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		gradle>=8.5:devel/gradle
RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix zip
CPE_VENDOR=	nsa

USE_JAVA=	yes
JAVA_VERSION=	17+

SHEBANG_FILES=	Ghidra/Features/BSim/make-postgres.sh \
		ghidraRun \
		server/ghidraSvr \
		server/jaas_external_program.example.sh \
		server/svrAdmin \
		server/svrInstall \
		server/svrUninstall \
		support/analyzeHeadless \
		support/bsim \
		support/bsim_ctl \
		support/buildGhidraJar \
		support/buildNatives \
		support/convertStorage \
		support/gdbGADPServerRun \
		support/ghidraClean \
		support/ghidraDebug \
		support/GhidraGo/ghidraGo \
		support/launch.sh \
		support/pythonRun \
		support/sleigh

SUB_FILES=	ghidra.desktop

WRKSRC=		${WRKDIR}/${PORTNAME}_${DISTVERSION}_PUBLIC

GRADLE_HOME_BASE=	/tmp
GRADLE_RUN=		${SETENV} ${MAKE_ENV} gradle --gradle-user-home \
			${GRADLE_HOME_BASE}/gradle-${PORTNAME} --no-daemon

BUILD_SUBDIR=	build/os/freebsd_x86_64
TMP_DIRS=	Ghidra/Ghidra/.gradle Ghidra/Features/Decompiler/build/objs \
		Ghidra/Features/Decompiler/build/tmp \
		Ghidra/Features/FileFormats/build/objs \
		Ghidra/Features/FileFormats/build/tmp GPL/.gradle \
		GPL/DemanglerGnu/build/objs GPL/DemanglerGnu/build/tmp \
		GPL/nativeBuildProperties.gradle.orig

PROGRAM_FILES=	Ghidra/Features/FileFormats/${BUILD_SUBDIR}/lzfse \
		Ghidra/Features/Decompiler/${BUILD_SUBDIR}/decompile \
		Ghidra/Features/Decompiler/${BUILD_SUBDIR}/sleigh \
		GPL/DemanglerGnu/${BUILD_SUBDIR}/demangler_gnu_v2_24 \
		GPL/DemanglerGnu/${BUILD_SUBDIR}/demangler_gnu_v2_41

do-build:
	@cd ${WRKSRC}/Ghidra && ${GRADLE_RUN} buildNatives
	@cd ${WRKSRC}/GPL/DemanglerGnu && ${GRADLE_RUN} build

pre-install:
	${REINPLACE_CMD} '1s|bash$$|bash\n\nexport JAVA_HOME="${JAVA_HOME}"|g' ${WRKSRC}/ghidraRun

do-install:
.for F in ${TMP_DIRS}
	${RM} -r ${WRKSRC}/${F}
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for F in ${SHEBANG_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${F}
	${INSTALL_SCRIPT} ${WRKSRC}/${F} ${STAGEDIR}${DATADIR}/${F}
.endfor
.for F in ${PROGRAM_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${F}
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${DATADIR}/${F}
.endfor
	${INSTALL_DATA} ${WRKDIR}/ghidra.desktop ${STAGEDIR}/${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/ghidra.svg ${STAGEDIR}${DATADIR}/ghidra.svg
	${RLN} ${STAGEDIR}${DATADIR}/ghidraRun ${STAGEDIR}/${PREFIX}/bin/ghidra
	cd ${STAGEDIR}${DATADIR}/support && ${MV} launch.properties launch.properties.sample

.include <bsd.port.mk>
