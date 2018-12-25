# $FreeBSD$

# This port opens too many files during build, more than the default setting.
# Its build is known to succeed with MAX_FILES_RStudio=2048 in poudriere.conf when ports-mgmt/poudriere-devel is used.

PORTNAME=	RStudio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.679
PORTREVISION=	7
CATEGORIES=	devel math java
MASTER_SITES=	https://s3.amazonaws.com/rstudio-dictionaries/:dictionaries \
		https://s3.amazonaws.com/rstudio-buildtools/:buildtools
DISTFILES=	core-dictionaries.zip:dictionaries \
		gin-${GIN_VERSION}.zip:buildtools \
		gwt-${GWT_VERSION}.zip:buildtools \
		mathjax-26.zip:buildtools

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Integrated development environment (IDE) for R

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ant:devel/apache-ant \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		pandoc:textproc/hs-pandoc
LIB_DEPENDS=	libR.so:math/R \
		libboost_thread.so:devel/boost-libs \
		libinotify.so:devel/libinotify \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake desktop-file-utils fortran pkgconfig qt:5 shared-mime-info ssl
USE_QT=		core dbus declarative gui location network opengl printsupport sensors \
		sql svg webchannel webengine webkit widgets xml xmlpatterns buildtools_build qmake_build
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tl}
GH_TUPLE=	rstudio:r2d3:v0.2.0:r2d3/dependencies/common/r2d3 \
		rstudio:rmarkdown:aed26ac:rmarkdown/dependencies/common/rmarkdown \
		rstudio:rsconnect:03c379b:rsconnect/dependencies/common/rsconnect \
		trestletech:plumber:v0.4.6:plumber/dependencies/common/plumber

CMAKE_ARGS=	-DRSTUDIO_TARGET=Desktop \
		-DFREEBSD_RSTUDIO_VERSION:STRING=${PORTVERSION} \
		-DFREEBSD_LIBDIR:STRING=${PREFIX}/lib
CMAKE_ARGS+=	-DRSTUDIO_BOOST_SIGNALS_VERSION=2 # until Boost 1.69 or RStudio 1.3
MAKE_ENV=	HOME=${WRKDIR} \
		ANT_OPTS="-Duser.home=${WRKDIR}"

GWT_VERSION=	2.8.1
GIN_VERSION=	2.1.2

post-extract:
	@${MKDIR} ${WRKSRC}/dependencies/common/dictionaries && ${MV} ${WRKDIR}/en_* ${WRKSRC}/dependencies/common/dictionaries/
	@${MV} ${WRKDIR}/mathjax-* ${WRKSRC}/dependencies/common/
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gwt && ${MV} ${WRKDIR}/gwt-${GWT_VERSION} ${WRKSRC}/src/gwt/lib/gwt/${GWT_VERSION}
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION} && ${MV} ${WRKDIR}/*.jar ${WRKDIR}/javadoc ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION}/

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
	@${REINPLACE_CMD} -e '\
		s|rHomePaths.push_back|//rHomePaths.push_back|; \
		s|//rHomePaths.push_back(FilePath("/usr/local/lib/|rHomePaths.push_back(FilePath("${PREFIX}/lib/|' \
		${WRKSRC}/src/cpp/core/r_util/RVersionsPosix.cpp

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
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${PREFIX}/lib/rstudio/bin/rstudio \"$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/rstudio
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/rstudio
	@${REINPLACE_CMD} -e 's|^Exec=.*/rstudio|Exec=${PREFIX}/bin/rstudio|' ${STAGEDIR}${PREFIX}/share/applications/rstudio.desktop
	# Some functions expect the pandoc symlink.
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/rstudio/bin/pandoc
	@cd ${STAGEDIR}${PREFIX}/lib/rstudio/bin/pandoc && ${LN} -s ../../../../bin/pandoc
	# There is a variability in .js file names due to the use of random numbers, so we use the automatic plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | ${GREP} -v ^\/ | ${SED} -e 's|%%WWWDIR%%|www/rstudio|' > ${TMPPLIST}

.include <bsd.port.mk>
