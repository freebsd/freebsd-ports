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

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES IPV6 JAVA OPENSSL PERL PYTHON
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

PERL_USES=	perl5 shebangfix
PERL_VARS=	staf_projects+=perl \
		shebang_files+=lang/perl/*.pl \
		perl_v=${PERL_VER:S/.//g}
PERL_MAKE_ARGS=	PERL_V${PERL_V}_ROOT=${LOCALBASE} \
		PERL_V${PERL_V}_LIBDIRS=${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE \
		PERL_V${PERL_V}_INCLUDEDIRS=${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE \
		PERL_BUILD_V${PERL_V}=1

PYTHON_USES=	python:-3.4
PYTHON_VARS=	staf_projects+=python \
		use_python=py3kplist
PYTHON_MAKE_ARGS=	PYTHON_V${PYTHON_SUFFIX}_ROOT=${LOCALBASE} \
			PYTHON_V${PYTHON_SUFFIX}_INCLUDEDIRS=${PYTHON_INCLUDEDIR} \
			PYTHON_V${PYTHON_SUFFIX}_LIBS=${PYTHON_VERSION}${PYTHON_ABIVER} \
			PYTHON_BUILD_V${PYTHON_SUFFIX}=1

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
STAF_PERL_SCRIPTS=	STAF.pl STAF2.pl
STAF_PERL_MODULES=	DeviceService.pm PLSTAF.pm PLSTAFService.pm STAFLog.pm \
			STAFMon.pm
STAF_PERL_LIBS=		libPLSTAF.so
STAF_PYLIB_FILES=	PySTAFLog.py PySTAFMon.py
STAF_SSL_FILES=	CAList.crt STAFDefault.crt STAFDefault.key
STAF_PERL_VERSIONS=	50 56 58 510 512 514 516 518 520
STAF_PYTHON_VERSIONS=	22 23 24 25 26 27 30 31 32 33 34
STAF_VAR_DIR?=	/var/db/STAF

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPERL}
BROKEN=	Perl >= 5.22 is not supported

.for i in ${STAF_PERL_VERSIONS}
.if ${PERL_V} != ${i}
PERL_MAKE_ARGS+=	PERL_BUILD_V${i}=0
.endif
.endfor
.endif

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_MAJOR_VER} == 2
STAF_PYLIB_FILES+=	PySTAF.py
PLIST_SUB+=		PYTHON_2="" PYTHON_3="@comment "
MAKE_ARGS+=		PYTHON_V${PYTHON_SUFFIX}_LIBDIRS=${PYTHON_LIBDIR}/config
.else
STAF_PYLIB_FILES+=	PySTAFv3.py
PLIST_SUB+=		PYTHON_3="" PYTHON_2="@comment "
MAKE_ARGS+=		PYTHON_V${PYTHON_SUFFIX}_LIBDIRS=${PYTHON_LIBDIR}/config-${PYTHON_VER}${PYTHON_ABIVER}
.endif

.for i in ${STAF_PYTHON_VERSIONS}
.if ${PYTHON_SUFFIX} != ${i}
PYTHON_MAKE_ARGS+=	PYTHON_BUILD_V${i}=0
.endif
.endfor
.endif

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
	${LN} -s STAF ${STAGEDIR}${PREFIX}/bin/staf
	${LN} -s FmtLog ${STAGEDIR}${PREFIX}/bin/fmtlog
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

do-install-PERL-on:
.for script in ${STAF_PERL_SCRIPTS}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/bin/${script} \
		${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
.for module in ${STAF_PERL_MODULES}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/bin/${module} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
.endfor
.for lib in ${STAF_PERL_LIBS}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/perl${PERL_V}/${lib} \
		${STAGEDIR}${PREFIX}/lib
.endfor

do-install-PYTHON-on:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.for lib in ${STAF_PYLIB_FILES}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/lib/${lib} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/python${PYTHON_SUFFIX}/PYSTAF.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${ECHO} ${PORTNAME} > ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}.pth

.include <bsd.port.post.mk>
