# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.13.0
CATEGORIES=	biology
MASTER_SITES=	http://ugene.unipro.ru/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} QueryDesigner_UserManual.pdf \
		UniproUGENE_UserManual.pdf WorkflowDesigner_UserManual.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2

.if !exists(/usr/include/execinfo.h)
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		qmake
USE_GL=		glu
USE_QT4=	gui webkit xml svg linguist_build moc_build qmake_build \
		qtestlib_build rcc_build uic_build imageformats_run \
		scripttools_build
USE_XORG=	xtst
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} UGENE_INSTALL_DATA=${DATADIR} \
		INSTALL_MANDIR=${MAN1PREFIX}/man
ALL_TARGET=	release

DOCSDIR=	${DATADIR}/manuals

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install official UGENE documentation (PDF)

.include <bsd.port.pre.mk>

# Required for Google Test code
.if ${OSVERSION} > 1000054
CXXFLAGS+=	-std=c++11
.endif

.if ${ARCH} == "amd64"
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
PLIST_SUB=	NOX64="@comment "
.else
PLIST_SUB=	NOX64=""
.endif

.if ${MACHINE_CPU:Msse2}
QMAKE_ARGS+=	UGENE_SSE2_DETECTED=1
.endif

post-extract:
	${CP} -p ${_DISTDIR}/*.pdf ${WRKSRC}/data/manuals

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene
	@${REINPLACE_CMD} -e '30s|^|#include <time.h>|' \
		${WRKSRC}/src/plugins/dbi_bam/src/BAMDbiPlugin.h
	@${REINPLACE_CMD} -e 's|runTime=NULL|runTime=0|' \
		${WRKSRC}/src/plugins/test_runner/src/TestViewReporter.h
	@${REINPLACE_CMD} -e 's|Q_OS_LINUX|Q_OS_UNIX|' \
		${WRKSRC}/src/ugenem/src/main.cpp
	@(cd ${WRKSRC}/src/plugins/external_tool_support/src && \
		${REINPLACE_CMD} -e 's/LINUX) || defined(Q_OS_MAC/UNIX/' \
			ExternalToolSupportPlugin.cpp \
			R/RSupport.cpp \
			blast/BlastAllSupport.cpp \
			blast/FormatDBSupport.cpp \
			blast_plus/BlastDBCmdSupport.cpp \
			blast_plus/BlastPlusSupport.cpp \
			bowtie/BowtieSupport.cpp \
			bowtie2/Bowtie2Support.cpp \
			bwa/BwaSupport.cpp \
			cap3/CAP3Support.cpp \
			clustalo/ClustalOSupport.cpp \
			clustalw/ClustalWSupport.cpp \
			cufflinks/CufflinksSupport.cpp \
			mrbayes/MrBayesSupport.cpp \
			perl/PerlSupport.cpp \
			python/PythonSupport.cpp \
			samtools/BcfToolsSupport.cpp \
			samtools/SamToolsExtToolSupport.cpp \
			spidey/SpideySupport.cpp \
			tcoffee/TCoffeeSupport.cpp \
			tophat/TopHatSupport.cpp \
			utils/ExternalToolSearchTask.cpp)

post-configure:
	@${REINPLACE_CMD} -e '/^LFLAGS/s,-pthread,-lexecinfo &,' \
		${WRKSRC}/src/ugenecl/Makefile.Release \
		${WRKSRC}/src/ugeneui/Makefile.Release

.include <bsd.port.post.mk>
