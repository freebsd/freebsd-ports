# This port opens too many files during build, more than the default setting.
# Its build is known to succeed with MAX_FILES_RStudio=4096 in poudriere.conf

PORTNAME=	RStudio
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.12.0+353
PORTREVISION=	10
CATEGORIES=	devel math java
MASTER_SITES=	https://s3.amazonaws.com/rstudio-buildtools/dictionaries/:dictionaries \
		https://s3.amazonaws.com/rstudio-buildtools/:buildtools
DISTFILES=	core-dictionaries.zip:dictionaries \
		gin-${GIN_VERSION}.zip:buildtools \
		gwt-${GWT_VERSION}.zip:buildtools \
		mathjax-27.zip:buildtools

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Integrated development environment (IDE) for R
WWW=		https://www.rstudio.com/ \
		https://github.com/rstudio/rstudio

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build with Boost>=1.87, see https://github.com/rstudio/rstudio/issues/15862
BROKEN_i386=	[ERROR] Line 101: Failed to resolve 'org.rstudio.studio.client.workbench.views.vcs.common.diff.LineActionButtonRenderer.GrayResources' via deferred binding

BUILD_DEPENDS=	ant:devel/apache-ant \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		node:www/node \
		pandoc:textproc/hs-pandoc \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi
LIB_DEPENDS=	libR.so:math/R \
		libboost_thread.so:devel/boost-libs \
		libinotify.so:devel/libinotify \
		libsoci_core.so:databases/soci \
		libuuid.so:misc/libuuid \
		libyaml-cpp.so:devel/yaml-cpp

FLAVORS=	desktop server
FLAVOR?=	${FLAVORS:[1]}
server_PKGNAMESUFFIX=	-server

USES=		cmake fortran java:build localbase:ldflags pgsql pkgconfig sqlite ssl
JAVA_VERSION=	11 # Java 8 fails on aarch64: Internal Error (assembler_aarch64.hpp:237), pid=1644, tid=0x00000000000c62b6 guarantee(val < (1U << nbits)) failed: Field too big for insn
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tl}
GH_TUPLE=	rstudio:r2d3:v0.2.0:r2d3/dependencies/common/r2d3 \
		rstudio:rmarkdown:aed26ac:rmarkdown/dependencies/common/rmarkdown \
		rstudio:rsconnect:03c379b:rsconnect/dependencies/common/rsconnect \
		trestletech:plumber:v0.4.6:plumber/dependencies/common/plumber

CMAKE_ARGS=	-DFREEBSD_RSTUDIO_VERSION:STRING=${PORTVERSION} \
		-DFREEBSD_LIBDIR:STRING=${PREFIX}/lib
CMAKE_ARGS+=	-DQT_QMAKE_EXECUTABLE:STRING=${QMAKE}
CMAKE_ARGS+=	-DRSTUDIO_BOOST_SIGNALS_VERSION=2
CMAKE_ARGS+=	-DFREEBSD_PORT_VERSION:STRING=${DISTVERSION}
CMAKE_ARGS+=	-DFREEBSD_LOCALBASE:STRING=${LOCALBASE} # SOCI package is looked up here, see patch patch-src_cpp_CMakeLists.txt
CMAKE_ON=	RSTUDIO_USE_SYSTEM_YAML_CPP \
		RSTUDIO_USE_SYSTEM_SOCI
MAKE_ENV=	HOME=${WRKDIR} \
		JAVA_HOME=${JAVA_HOME} \
		PATH=${JAVA_HOME}/bin:${PATH} \
		ANT_OPTS="-Duser.home=${WRKDIR}"
LDFLAGS+=	-lexecinfo

GWT_VERSION=	2.8.1
GIN_VERSION=	2.1.2

.if ${FLAVOR:U} == desktop
COMMENT+=	(desktop UI version)
USES+=		desktop-file-utils qt:5 shared-mime-info
USE_QT=		core dbus declarative gui location network opengl printsupport quickcontrols sensors \
		sql svg webchannel webengine widgets xml xmlpatterns buildtools:build qmake:build
CMAKE_ARGS+=	-DRSTUDIO_TARGET=Desktop
INSTALL_SUBDIR=	${PORTNAME:tl}
EXECUTABLE=	${PORTNAME:tl}
.endif

.if ${FLAVOR:U} == server
COMMENT+=	(web UI version)
CMAKE_ARGS+=	-DRSTUDIO_TARGET=Server
LDFLAGS+=	-linotify
INSTALL_SUBDIR=	${PORTNAME:tl}-server
EXECUTABLE=	rserver
USER=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME:tl}-server
.endif

OPTIONS_DEFINE=		WITH_QUARTO

WITH_QUARTO_DESC=	Build with support for Quarto
WITH_QUARTO_CMAKE_BOOL=	FREEBSD_QUARTO_ENABLED
WITH_QUARTO_BROKEN=	Quarto isn't yet ported

post-extract:
	@${MKDIR} ${WRKSRC}/dependencies/dictionaries && ${MV} ${WRKDIR}/en_* ${WRKSRC}/dependencies/dictionaries/
	@${MV} ${WRKDIR}/mathjax-* ${WRKSRC}/dependencies/
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gwt && ${MV} ${WRKDIR}/gwt-${GWT_VERSION} ${WRKSRC}/src/gwt/lib/gwt/${GWT_VERSION}
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION} && ${MV} ${WRKDIR}/*.jar ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION}/

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|target_link_libraries(rstudio|target_link_libraries(rstudio procstat|; \
		s|get_filename_component|#get_filename_component|; \
		s|set(CMAKE_PREFIX_PATH "$${QT_BIN_DIR}//..//lib//cmake")|set(CMAKE_PREFIX_PATH "${LOCALBASE}/lib/cmake")|; \
		s|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/src/cpp/desktop/CMakeLists.txt
	@${REINPLACE_CMD} -e ' \
		s|</java>|<jvmarg value="-Duser.home=${WRKDIR}"/></java>|' \
		${WRKSRC}/src/gwt/build.xml
	@${REINPLACE_CMD} -e ' \
		s|rHomePaths.push_back|//rHomePaths.push_back|; \
		s|//rHomePaths.push_back(FilePath("/usr/local/lib/|rHomePaths.push_back(FilePath("${PREFIX}/lib/|' \
		${WRKSRC}/src/cpp/core/r_util/RVersionsPosix.cpp
	@${REINPLACE_CMD} -e ' \
		s|<condition property="node.bin" value="../../../$${node.dir}/bin/node">|<condition property="node.bin" value="${LOCALBASE}/bin/node">|' \
		${WRKSRC}/src/gwt/build.xml
	# add $PREFIX/bin to PATH for the server daemon
.if ${FLAVOR:U} == server
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/cpp/session/modules/SessionGit.cpp
.endif

pre-build:
	@${CP} ${FILESDIR}/global-setenv.h ${WRKSRC}/src/cpp/desktop/
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/cpp/desktop/global-setenv.h

post-install:
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "if ! [ -d /proc/curproc ]; then"; \
	  echo "  echo \"${PORTNAME} needs /proc to be mounted as procfs\" >&2"; \
	  echo "  exit 1"; \
	  echo "fi"; \
	  echo ""; \
	  echo "# workaround for the problem that RStudio passes /lib with LD_LIBRARY_PATH that causes the /lib/libgcc_s.so.1 conflict with gcc"; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so JAVA_HOME=${JAVA_HOME} ${PREFIX}/lib/${INSTALL_SUBDIR}/bin/${EXECUTABLE} \"$$"@"\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
.if ${FLAVOR:U} == desktop
	${REINPLACE_CMD} -i '' -e 's|^Exec=.*/rstudio|Exec=${PREFIX}/bin/${EXECUTABLE}|' ${STAGEDIR}${PREFIX}/share/applications/${EXECUTABLE}.desktop
.endif
.if ${FLAVOR:U} == server
	${RM} ${STAGEDIR}${LOCALBASE}/lib/${INSTALL_SUBDIR}/bin/rstudio-server # not compatible with FreeBSD
.endif
	# Some functions expect the pandoc symlink.
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${INSTALL_SUBDIR}/bin/pandoc
	@cd ${STAGEDIR}${PREFIX}/lib/${INSTALL_SUBDIR}/bin/pandoc && ${LN} -s ../../../../bin/pandoc
	# There is a variability in .js file names due to use of random numbers, so we use the automatic plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | ${GREP} -v ^\/ | ${SED} -e 's|%%WWWDIR%%|www/rstudio| ; s|%%CMAKE_BUILD_TYPE%%|${CMAKE_BUILD_TYPE:tl}|' > ${TMPPLIST}

.include <bsd.port.mk>
