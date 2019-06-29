# $FreeBSD$

PORTNAME=		ghidra
DISTVERSIONPREFIX=	Ghidra_
DISTVERSION=	9.0.4
DISTVERSIONSUFFIX=	_build
CATEGORIES=		devel security
MASTER_SITES=	SF/yajsw/yajsw/yajsw-stable-12.12/:yajsw \
	SF/catacombae/HFSExplorer/0.21/:hfsexplorer \
	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/android4me/:axml2printer \
	https://github.com/pxb1988/dex2jar/releases/download/2.0/:dex2jar
DISTFILES=		yajsw-stable-12.12.zip:yajsw \
	hfsexplorer-0_21-bin.zip:hfsexplorer \
	AXMLPrinter2.jar:axml2printer \
	dex-tools-2.0.zip:dex2jar
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Software reverse engineering (SRE) framework

LICENSE=		APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
BUILD_DEPENDS=	gradle>=5.0:devel/gradle \
	bash:shells/bash \
	flex:textproc/flex \
	fop:textproc/fop \
	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
RUN_DEPENDS=	bash:shells/bash

USES=	bison shebangfix

OPTIONS_RADIO=	JDK
OPTIONS_RADIO_JDK=	JDK11 JDK12
OPTIONS_DEFAULT=	JDK11

JDK11_BUILD_DEPENDS=	${LOCALBASE}/openjdk11/bin/java:java/openjdk11
JDK11_RUN_DEPENDS=		${LOCALBASE}/openjdk11/bin/java:java/openjdk11
JDK12_BUILD_DEPENDS=	${LOCALBASE}/openjdk12/bin/java:java/openjdk12
JDK12_RUN_DEPENDS=		${LOCALBASE}/openjdk12/bin/java:java/openjdk12

SHEBANG_FILES=	Ghidra/RuntimeScripts/Linux/* \
	Ghidra/RuntimeScripts/Linux/support/* \
	Ghidra/RuntimeScripts/Linux/server/*

USE_GITHUB=	yes
GH_ACCOUNT=	NationalSecurityAgency

GRADLE_HOME_BASE=	/tmp	# Gradle cache path must be absolute (see https://github.com/gradle/gradle/issues/1338)
GRADLE_RUN=	${SETENV} ${MAKE_ENV} gradle \
			--gradle-user-home ${GRADLE_HOME_BASE}/gradle-${PORTNAME} \
			--no-daemon

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${GRADLE_HOME_BASE} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@${ECHO} "(!!!) Please upload the Gradle deps archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	https://github.com/sghctoma/ghidra-deps/raw/master/:gradle
DISTFILES+=		${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:gradle
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

post-patch-JDK11-on:
	@${ECHO_CMD} "org.gradle.java.home=${LOCALBASE}/openjdk11" > ${WRKSRC}/gradle.properties

post-patch-JDK12-on:
	@${ECHO_CMD} "org.gradle.java.home=${LOCALBASE}/openjdk12" > ${WRKSRC}/gradle.properties

do-build:
	cd ${WRKSRC} && ${GRADLE_RUN} yajswDevUnpack
	cd ${WRKSRC} && ${GRADLE_RUN} buildGhidra

post-build:
	@${RM} ${GRADLE_HOME_BASE}/gradle-${PORTNAME}

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
