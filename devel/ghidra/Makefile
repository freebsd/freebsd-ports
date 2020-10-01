# $FreeBSD$

PORTNAME=	ghidra
DISTVERSIONPREFIX=	Ghidra_
DISTVERSION=	9.1
DISTVERSIONSUFFIX=	_build
CATEGORIES=	devel security java
MASTER_SITES=	SF/yajsw/yajsw/yajsw-stable-12.12/:yajsw \
		SF/catacombae/HFSExplorer/0.21/:hfsexplorer \
		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/android4me/:axml2printer \
		https://github.com/pxb1988/dex2jar/releases/download/2.0/:dex2jar
DISTFILES=	yajsw-stable-12.12.zip:yajsw \
		hfsexplorer-0_21-bin.zip:hfsexplorer \
		AXMLPrinter2.jar:axml2printer \
		dex-tools-2.0.zip:dex2jar
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Software reverse engineering (SRE) framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
			bash:shells/bash \
			flex:textproc/flex \
			fop:textproc/fop \
			gradle5>=5.0:devel/gradle5
RUN_DEPENDS=		bash:shells/bash

USES=		bison shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	NationalSecurityAgency

USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_BUILD=	yes
JAVA_RUN=	yes

SHEBANG_FILES=	Ghidra/RuntimeScripts/Common/server/jaas_external_program.example.sh \
		Ghidra/RuntimeScripts/Linux/* \
		Ghidra/RuntimeScripts/Linux/server/* \
		Ghidra/RuntimeScripts/Linux/support/*


# Gradle cache path must be absolute (see https://github.com/gradle/gradle/issues/1338)
GRADLE_HOME_BASE=	/tmp
GRADLE_RUN=		${SETENV} ${MAKE_ENV} gradle5 --gradle-user-home \
			${GRADLE_HOME_BASE}/gradle-${PORTNAME} --no-daemon

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "no")
MASTER_SITES+=	https://github.com/sghctoma/ghidra-deps/raw/master/:gradle
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:gradle
EXTRACT_ONLY+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}
GRADLE_RUN+=	--offline
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/flatrepo
	@${MKDIR} ${WRKDIR}/dummy.home
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/AXMLPrinter2.jar ${WRKDIR}/flatrepo
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/hfsexplorer-0_21-bin.zip \
		lib/csframework.jar lib/hfsx_dmglib.jar lib/hfsx.jar lib/iharder-base64.jar
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/dex-tools-2.0.zip "dex2jar-2.0/lib/dex-*.jar"
	@${MKDIR} ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/yajsw-stable-12.12.zip ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/
.if (${DEV_UPDATE_MODE} == "no")
	@${LN} -sf ${WRKDIR}/gradle-${PORTNAME} ${GRADLE_HOME_BASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets|${LOCALBASE}/share/xsl/docbook/|g" \
		${WRKSRC}/Ghidra/Features/Decompiler/src/main/doc/*.xsl \
		${WRKSRC}/Ghidra/Features/FunctionID/src/main/doc/*.xsl
	@${REINPLACE_CMD} -e "s|JAVA_HOME_PLACEHOLDER|${JAVA_HOME}|" \
		${WRKSRC}/Ghidra/RuntimeScripts/Linux/support/launch.sh
	@${ECHO_CMD} "org.gradle.java.home=${JAVA_HOME}" > ${WRKSRC}/gradle.properties

do-build:
	@cd ${WRKSRC} && ${GRADLE_RUN} yajswDevUnpack buildGhidra

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	cd ${GRADLE_HOME_BASE} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@${ECHO} "(!!!) Please upload the Gradle deps archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
	@${RM} -r ${GRADLE_HOME_BASE}/gradle-${PORTNAME}
.endif

do-install:
	@${UNZIP_CMD} -d ${STAGEDIR} ${WRKSRC}/build/dist/*.zip
	@${MV} ${STAGEDIR}/ghidra* ${STAGEDIR}${DATADIR}
	@${RLN} ${STAGEDIR}/${DATADIR}/ghidraRun ${STAGEDIR}${PREFIX}/bin/ghidra
	@${RLN} ${STAGEDIR}/${DATADIR}/server/ghidraSvr ${STAGEDIR}${PREFIX}/bin/ghidra-server
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/GPL/DemanglerGnu/os/freebsd64/demangler_gnu
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd64/decompile
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd64/sleigh

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
