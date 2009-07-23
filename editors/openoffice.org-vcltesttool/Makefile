# New ports collection makefile for: OpenOffice.org VCLTestTool
# Date created:		2009/7/11
# Whom:                 NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openoffice.org-vcltesttool
PORTVERSION=	2.4.${SNAPDATE}
CATEGORIES+=	editors java
MASTER_SITES+=	http://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unowinreg
DISTFILES+=	${OOOSRC} unowinreg.dll:unowinreg
EXTRACT_ONLY=	${OOOSRC}

MAINTAINER=	openoffice@FreeBSD.org
COMMENT=	Automated testtool for the openoffice.org

USE_GNOME=	desktopfileutils gtk20 gnomevfs2
USE_XORG=	x11 ice xaw xau xext xrender xrandr \
		xi xt xcursor xdamage xcomposite xfixes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_BZIP2=	yes
WITHOUT_CPU_CFLAGS=	true
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	freebsd bsdjava openjdk
.if (${OSVERSION} >= 700000)
JAVA_VERSION=	1.5 1.6
.else
JAVA_VERSION=	1.4 1.5 1.6
.endif

ONLY_FOR_ARCHS=	i386 amd64

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set
.else
FREEBSD_ENV_SET=	FreeBSDX86Env.Set
.endif

#Linux/Solaris/Windows m226, MacOSX: m243
MILESTONE=		248
OOOTAG=			SRC680_m${MILESTONE}
OOOSRC=			OOo_${OOOTAG}_source${EXTRACT_SUFX}
SNAPDATE=		20080302
INSTALLATION_BASEDIR?=	openoffice.org-vcltesttool
EXECBASE?=		openoffice.org-vcltesttool
DIST_SUBDIR=		openoffice.org2
SIMPLEOSVER=		${OSREL:C/\.//g}

.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
OOOCC=		${CCACHE_PREFIX} ${CC}
OOOCXX=		${CCACHE_PREFIX} ${CXX}
.else
OOOCC=		${CC}
OOOCXX=		${CXX}
.endif

CONFIGURE_ENV+=	CC="${OOOCC}" CXX="${OOOCXX}"		\
		CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib" \
		PATH=${WRKSRC}/solenv/bin:$$PATH

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		bash:${PORTSDIR}/shells/bash \
		imake:${PORTSDIR}/devel/imake \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		ant:${PORTSDIR}/devel/apache-ant

LIB_DEPENDS+=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base

USE_BISON=	build
GNU_CONFIGURE=	yes
WRKSRC?=		${WRKDIR}/${OOOTAG}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh

.if defined(DISABLE_MAKE_JOBS)
MAKE_JOBS_NUMBER=	1
.endif

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp		\
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--enable-crashdump=yes				\
			--with-system-zlib				\
			--disable-mozilla				\
			--disable-odk					\
			--without-nas					\
			--with-system-stdlibs				\
			--with-epm=internal				\
			--with-jdk-home="${JAVA_HOME}"			\
			--disable-binfilter

.if ${ARCH} == amd64
WITHOUT_MOZILLA=	yes
LIB_DEPENDS+=		boost_regex:${PORTSDIR}/devel/boost
CONFIGURE_ARGS+=	--with-system-boost=yes #i58343#
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/

pre-configure:
#Workaround for gperf. #i85469#
	@${LN} -sf ${LOCALBASE}/bin/gperf ${WRKSRC}/solenv/bin/gperf

do-build:
	@cd ${WRKSRC} ; ./bootstrap
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source ${FREEBSD_ENV_SET} ; setenv TMP ${WRKSRC} ; cd instsetoo_native ; build.pl --checkmodules ; build.pl -P${MAKE_JOBS_NUMBER} --all --html --dontgraboutput -- -P${MAKE_JOBS_NUMBER}"

do-install:
	${RM} -Rf ${WRKDIR}/tmp ${WRKDIR}/${INSTALLATION_BASEDIR}
	${MKDIR} ${WRKDIR}/tmp ${WRKDIR}/${INSTALLATION_BASEDIR}
	cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/ ; ${LS} *.t?z > ${WRKDIR}/INSTALLFILES
	for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/$$i ; \
	done
	${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
	${MV} ${PREFIX}/${INSTALLATION_BASEDIR}/program/soffice ${PREFIX}/${INSTALLATION_BASEDIR}/program/testtool
#following looks like the official process but lacks some files for FBSD.
#ftp "http://qa.openoffice.org/source/browse/*checkout*/qa/qatesttool/tools/standaloneTestTool/createTestTool.pl?rev=1.7"
#mv createTestTool.pl\?rev=1.7 createTestTool.pl
#ftp "http://qa.openoffice.org/source/browse/*checkout*/qa/qatesttool/tools/standaloneTestTool/filelinx.txt?rev=1.10"
#mv filelinx.txt\?rev=1.10 filefbsd.txt
#perl createTestTool.pl filefbsd.txt /work/VCLTestTool/openoffice.org-vcltesttool/work/SRC680_m248/solver/680/unxfbsdi.pro/lib/ ./vcl/
	#cd ${WRKDIR} ; ${PERL} ${FILESDIR}/createTestTool.pl ${FILESDIR}/filefbsd.txt ${WRKSRC}/solver/680/unxfbsd?.pro/lib/ ${INSTALLATION_BASEDIR}/
	#${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	#cd ${WRKDIR} ; ${TAR} xf ${WRKDIR}/tt_680unxfbsd?.pro.tar -C ${PREFIX}/

post-install:
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice.org-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice.org-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${ECHO_CMD} "" > ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin \( -type f -or -type l \) -name "${EXECBASE}*" >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} \( -type f -or -type l \) >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} ${INSTALLATION_BASEDIR} -type d | ${SORT} -r | \
		${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}

.include <bsd.port.post.mk>
