# Created by: Sergey Kozlov <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	staf
PORTVERSION=	3.4.26
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V${PORTVERSION}
DISTNAME=	STAF${PORTVERSION:S/.//g}-src

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Software Testing Automation Framework

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.htm

WRKSRC=		${WRKDIR}/src
WRKSRC_SUBDIR=	${PORTNAME}
INSTALL_WRKSRC=	${WRKDIR}/rel/freebsd/staf/${STAF_BUILD_TYPE}

MAKEFILE=	makefile
MAKE_ARGS=	OS_NAME="freebsd" \
		CC_CC=${CXX} \
		CC_C=${CC} \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		STAF_USE_SSL=${STAF_USE_SSL} \
		STAF_USE_IPV6=${STAF_USE_IPV6} \
		ZLIB_ROOT=/usr \
		BUILD_TYPE=${STAF_BUILD_TYPE} \
		PROJECTS="${STAF_PROJECTS}"

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES IPV6 JAVA OPENSSL
OPTIONS_DEFAULT=OPENSSL
OPTIONS_SUB=	yes

DEBUG_VARS=	staf_build_type=debug
DEBUG_VARS_OFF=	staf_build_type=retail

IPV6_VARS=	staf_use_ipv6=1
IPV6_VARS_OFF=	staf_use_ipv6=""

JAVA_VARS=	staf_projects+=java \
		staf_projects+=event \
		staf_projects+=ftp \
		staf_projects+=fsext \
		staf_projects+=namedcounter \
		staf_projects+=sxe \
		staf_projects+=timer \
		use_java=yes
JAVA_MAKE_ARGS=	JAVA_V12_ROOT=${JAVA_HOME} \
		JAVAC_V12=${JAVAC} \
		JAVAH_V12=${JAVAH} \
		JAVA_V12=${JAVA} \
		JAR_V12=${JAR} \
		JAVA_BUILD_V12=1

OPENSSL_VARS=		staf_use_ssl=1
OPENSSL_USES=		ssl
OPENSSL_MAKE_ARGS=	OPENSSL_ROOT=${OPENSSLBASE} \
			OPENSSL_LIBDIRS="${OPENSSLLIB}" \
			OPENSSL_INCLUDEDIRS=${OPENSSLINC}
OPENSSL_VARS_OFF=	staf_use_ssl=""

MAKE_JOBS_UNSAFE=	yes
USES=		gmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	stafproc
USE_CXXSTD=	gnu++98
SUB_LIST+=	STAF_VAR_DIR=${STAF_VAR_DIR}
PLIST_SUB+=	STAF_VAR_DIR=${STAF_VAR_DIR}

STAF_PROJECTS=	staf connprov_tcp connprov_localipc zip
STAF_BIN_FILES=	STAF STAFProc STAFReg STAFLoop STAFExecProxy FmtLog
STAF_LIB_FILES=	libHello.so libSTAF.so libSTAFDSLS.so libSTAFDeviceService.so \
		libSTAFEXECPROXY.so libSTAFLIPC.so libSTAFLog.so \
		libSTAFMon.so libSTAFPool.so libSTAFReg.so libSTAFTCP.so \
		libSTAFZip.so
STAF_JAVA_LIBS=	libJSTAF.so libJSTAFSH.so
STAF_JAVA_JARS=	JSTAF.jar STAFHTTPSLS.jar
STAF_SSL_FILES=	CAList.crt STAFDefault.crt STAFDefault.key
STAF_VAR_DIR?=	/var/db/STAF

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "s|%%DATADIR%%|${DATADIR}|" \
		${WRKSRC}/stafif/STAFConverter.cpp \
		${WRKSRC}/connproviders/tcp/STAFTCPConnProvider.cpp
	${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/stafproc/STAFProc.cpp
	${REINPLACE_CMD} "s|%%STAFVARDIR%%|${STAF_VAR_DIR}|g" \
		${WRKSRC}/stafproc/STAFProc.cpp

do-install:
.for bin in ${STAF_BIN_FILES}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${bin} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/bin/STAF ${STAGEDIR}${PREFIX}/bin/staf
	${RLN} ${STAGEDIR}${PREFIX}/bin/FmtLog ${STAGEDIR}${PREFIX}/bin/fmtlog
.for lib in ${STAF_LIB_FILES}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/${lib} ${STAGEDIR}${PREFIX}/lib/
.endfor
	${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/STAF.cfg \
		${STAGEDIR}${PREFIX}/etc/STAF.cfg.sample
	(cd ${INSTALL_WRKSRC}/include && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include)
	${MKDIR} ${STAGEDIR}${DATADIR}/codepage
	(cd ${INSTALL_WRKSRC}/codepage && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/codepage)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${INSTALL_WRKSRC}/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${STAF_VAR_DIR}

do-install-DOCS-on:
	[ -d ${INSTALL_WRKSRC}/docs/staf ] && \
		${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		(cd ${INSTALL_WRKSRC}/docs/staf && \
			${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}) || true

do-install-JAVA-on:
.for javalib in ${STAF_JAVA_LIBS}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/${javalib} \
		${STAGEDIR}${PREFIX}/lib
.endfor
.for jar in ${STAF_JAVA_JARS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/lib/${jar} \
		${STAGEDIR}${JAVAJARDIR}
.endfor

do-install-OPENSSL-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for sslfile in ${STAF_SSL_FILES}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${sslfile} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.post.mk>
