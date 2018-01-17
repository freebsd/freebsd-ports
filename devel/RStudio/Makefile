# $FreeBSD$

# This port opens too many files during build, more than the default setting.
# Its build is known to succeed with MAX_FILES_RStudio=2048 in poudriere.conf when ports-mgmt/poudriere-devel is used.

PORTNAME=	RStudio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.409
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

USES=		cmake:outsource desktop-file-utils fortran pkgconfig shared-mime-info
USE_QT5=	core dbus gui location network opengl printsupport qml quick sensors \
		sql svg webchannel webkit widgets xml xmlpatterns buildtools_build qmake_build
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tl}
GH_TUPLE=	rstudio:rmarkdown:aed26ac:rmarkdown/dependencies/common/rmarkdown \
		rstudio:rsconnect:03c379b:rsconnect/dependencies/common/rsconnect

CMAKE_ARGS=	-DRSTUDIO_TARGET=Desktop \
		-DFREEBSD_RSTUDIO_VERSION:STRING=${PORTVERSION} \
		-DFREEBSD_LIBDIR:STRING=${PREFIX}/lib
MAKE_ENV=	HOME=${WRKDIR} \
		ANT_OPTS="-Duser.home=${WRKDIR}"

GWT_VERSION=	2.7.0
GIN_VERSION=	1.5

post-extract:
	@${MKDIR} ${WRKSRC}/dependencies/common/dictionaries && ${MV} ${WRKDIR}/en_* ${WRKSRC}/dependencies/common/dictionaries/
	@${MV} ${WRKDIR}/mathjax-* ${WRKSRC}/dependencies/common/
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gwt && ${MV} ${WRKDIR}/gwt-${GWT_VERSION} ${WRKSRC}/src/gwt/lib/gwt/${GWT_VERSION}
	@${MKDIR} ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION} && ${MV} ${WRKDIR}/*.jar ${WRKDIR}/javadoc ${WRKSRC}/src/gwt/lib/gin/${GIN_VERSION}/

post-patch:
	@${REINPLACE_CMD} -e ' \
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
	@${LN} -s ${PREFIX}/lib/rstudio/bin/rstudio ${STAGEDIR}${PREFIX}/bin/rstudio
	@${REINPLACE_CMD} -e 's|^Exec=.*/rstudio|Exec=${PREFIX}/bin/rstudio|' ${STAGEDIR}${PREFIX}/share/applications/rstudio.desktop
	# There is a variability in .js file names due to the use of random numbers, so we use the automatic plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | ${GREP} -v ^\/ | ${SED} -e 's|%%WWWDIR%%|www/rstudio|' > ${TMPPLIST}

.include <bsd.port.mk>
