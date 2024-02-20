PORTNAME=	ghidra-cheri
PORTVERSION=	${GHIDRA_VERSION}.d${SNAPDATE}
PORTREVISION=	0
CATEGORIES=	devel security java

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	ghidra
GH_TAGNAME=	${GHIDRA_COMMIT}

MAINTAINER=	zyj20@cl.cam.ac.uk
COMMENT=	Software reverse engineering (SRE) framework
WWW=		https://github.com/CTSRD-CHERI/ghidra

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS= aarch64	amd64

NOT_FOR_ABIS=	purecap
NOT_FOR_ABIS_REASON_purecap=is not adapted for CheriABI yet

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
BUILD_DEPENDS=		bash:shells/bash \
			gradle>=7.3:devel/gradle \
			protoc:devel/protobuf
RUN_DEPENDS=		bash:shells/bash \
			protoc:devel/protobuf

USES=		bison cpe shebangfix
CPE_VENDOR=	nsa

USE_JAVA=	yes
JAVA_VERSION=	17+
JAVA_BUILD=	yes
JAVA_RUN=	yes

SHEBANG_FILES=	Ghidra/RuntimeScripts/Common/server/jaas_external_program.example.sh \
		Ghidra/RuntimeScripts/Linux/* \
		Ghidra/RuntimeScripts/Linux/server/* \
		Ghidra/RuntimeScripts/Linux/support/* \
		Ghidra/Features/BSim/make-postgres.sh \
		Ghidra/Debug/Debugger-agent-frida/src/main/sh/execjar.sh \
		Ghidra/Debug/Debugger-agent-lldb/src/main/sh/execjar.sh \
		Ghidra/Debug/Debugger-agent-gdb/data/debugger-launchers/local-gdb.sh \
		Ghidra/Debug/Debugger-agent-gdb/src/main/sh/execjar.sh \
		Ghidra/Debug/Debugger-swig-lldb/macos_debugger_lldb_build_from_brew.sh


# Gradle cache path must be absolute (see https://github.com/gradle/gradle/issues/1338)
GRADLE_HOME_BASE=	/tmp
GRADLE_RUN=		${SETENV} ${MAKE_ENV} gradle --gradle-user-home \
			${GRADLE_HOME_BASE}/gradle-${PORTNAME} --no-daemon

.include "${.CURDIR}/Makefile.snapshot"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|JAVA_HOME_PLACEHOLDER|${JAVA_HOME}|" \
		${WRKSRC}/Ghidra/RuntimeScripts/Linux/support/launch.sh
	@${ECHO_CMD} "org.gradle.java.home=${JAVA_HOME}" > ${WRKSRC}/gradle.properties

do-build:
	@cd ${WRKSRC} && ${GRADLE_RUN} -I gradle/support/fetchDependencies.gradle init
	@cd ${WRKSRC} && ${GRADLE_RUN} buildGhidra

do-install:
	@${UNZIP_CMD} -d ${STAGEDIR} ${WRKSRC}/build/dist/*.zip
	@${MV} ${STAGEDIR}/ghidra* ${STAGEDIR}${DATADIR}
	@${RLN} ${STAGEDIR}/${DATADIR}/ghidraRun ${STAGEDIR}${PREFIX}/bin/ghidra-cheri
	@${RLN} ${STAGEDIR}/${DATADIR}/server/ghidraSvr ${STAGEDIR}${PREFIX}/bin/ghidra-server-cheri
	@${RLN} ${STAGEDIR}/${DATADIR}/support/analyzeHeadless ${STAGEDIR}${PREFIX}/bin/ghidra-headless-cheri
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/GPL/DemanglerGnu/os/freebsd_arm_64/demangler_gnu*
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd_arm_64/decompile
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd_arm_64/sleigh

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
