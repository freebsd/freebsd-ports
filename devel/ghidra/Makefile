PORTNAME=	ghidra
DISTVERSION=	11.4.2
CATEGORIES=	devel security java
MASTER_SITES=	https://github.com/NationalSecurityAgency/${PORTNAME}/releases/download/Ghidra_${DISTVERSION}_build/
DISTNAME=	${PORTNAME}_${DISTVERSION}_PUBLIC_20250826

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Software reverse engineering (SRE) framework
WWW=		https://ghidra-sre.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		gradle>=8.12:devel/gradle
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:gcc-c++11-lib cpe java python shebangfix zip
CPE_VENDOR=	nsa
JAVA_VERSION=	21+

SHEBANG_FILES=	docker/build-docker-image.sh \
		docker/entrypoint.sh \
		Ghidra/Debug/Debugger-agent-drgn/data/debugger-launchers/*.sh \
		Ghidra/Debug/Debugger-agent-gdb/data/debugger-launchers/*.sh \
		Ghidra/Debug/Debugger-agent-gdb/data/support/gdbsetuputils.sh \
		Ghidra/Debug/Debugger-agent-lldb/data/debugger-launchers/*.sh \
		Ghidra/Debug/Debugger-agent-lldb/data/support/*.sh \
		Ghidra/Debug/Debugger-agent-lldb/data/support/lldbsetuputils.sh \
		Ghidra/Debug/Debugger-isf/support/runISFServer \
		Ghidra/Debug/Debugger-rmi-trace/data/debugger-launchers/raw-python3.sh \
		Ghidra/Debug/Debugger-rmi-trace/data/support/setuputils.sh \
		Ghidra/Features/BSim/support/make-postgres.sh \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/*.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/distutils/command/build_scripts.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/distutils/tests/*.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/encodings/rot_13.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/ensurepip/__init__.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/lib2to3/fixes/fix_metaclass.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/lib2to3/pgen2/token.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/lib2to3/tests/data/different_encoding.py \
		Ghidra/Features/Jython/data/jython-2.7.4/Lib/lib2to3/tests/pytree_idempotency.py \
		Ghidra/Features/PyGhidra/pypkg/setup.py \
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
		support/convertStorage \
		support/gdbGADPServerRun \
		support/ghidraClean \
		support/ghidraDebug \
		support/GhidraGo/ghidraGo \
		support/jshellRun \
		support/jythonRun \
		support/launch.sh \
		support/pyghidraRun \
		support/sleigh

SUB_FILES=	ghidra.desktop

WRKSRC=		${WRKDIR}/${PORTNAME}_${DISTVERSION}_PUBLIC

GRADLE_HOME_BASE=	/tmp
GRADLE_RUN=		${SETENV} ${MAKE_ENV} gradle --gradle-user-home \
			${GRADLE_HOME_BASE}/gradle-${PORTNAME} --no-daemon

BUILD_SUBDIR=	build/os/freebsd_x86_64
TMP_DIRS=	Ghidra/.gradle \
		Ghidra/Features/Decompiler/build/objs \
		Ghidra/Features/Decompiler/build/tmp \
		Ghidra/Features/FileFormats/build/objs \
		Ghidra/Features/FileFormats/build/tmp \
		Ghidra/Ghidra/.gradle \
		Ghidra/build \
		GPL/.gradle \
		GPL/DemanglerGnu/build/objs \
		GPL/DemanglerGnu/build/tmp \
		GPL/build \
		GPL/nativeBuildProperties.gradle.orig \
		support/gradle/.gradle

PROGRAM_FILES=	Ghidra/Features/FileFormats/${BUILD_SUBDIR}/lzfse \
		Ghidra/Features/Decompiler/${BUILD_SUBDIR}/decompile \
		Ghidra/Features/Decompiler/${BUILD_SUBDIR}/sleigh \
		GPL/DemanglerGnu/${BUILD_SUBDIR}/demangler_gnu_v2_24 \
		GPL/DemanglerGnu/${BUILD_SUBDIR}/demangler_gnu_v2_41

do-build:
	@cd ${WRKSRC}/support/gradle && ${GRADLE_RUN} build

pre-install:
	${REINPLACE_CMD} '1s|bash$$|bash\n\nexport JAVA_HOME="${JAVA_HOME}"|g' \
		${WRKSRC}/ghidraRun

do-install:
.for F in ${TMP_DIRS}
	${RM} -r ${WRKSRC}/${F}
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for F in ${SHEBANG_FILES}
	@for fname in `ls ${WRKSRC}/${F} | ${XARGS} basename`; do \
		xfname="`dirname $F`/$$fname"; \
		${RM} ${STAGEDIR}${DATADIR}/$$xfname; \
		${INSTALL_SCRIPT} ${WRKSRC}/$$xfname ${STAGEDIR}${DATADIR}/$$xfname; \
	done
.endfor
.for F in ${PROGRAM_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${F}
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${DATADIR}/${F}
.endfor
	${INSTALL_DATA} ${WRKDIR}/ghidra.desktop ${STAGEDIR}/${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/ghidra.svg ${STAGEDIR}${DATADIR}/ghidra.svg
	${RLN} ${STAGEDIR}${DATADIR}/ghidraRun ${STAGEDIR}/${PREFIX}/bin/ghidra

.include <bsd.port.mk>
