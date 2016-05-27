# Created by: Kyle Martin <mkm@ieee.org>
# $FreeBSD$

PORTNAME=	cmake
PORTVERSION=	3.5.2
PORTREVISION?=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.cmake.org/files/v${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Cross-platform Makefile generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

USE_KDE4=	# env
CONFIGURE_ENV=	MAKE=make
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--system-libs \
		--parallel=${MAKE_JOBS_NUMBER} \
		--init="${PATCHDIR}/InitialCache.cmake"

.if !defined(CMAKE_MODULES)
OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes
USES+=		libarchive
HAS_CONFIGURE=	yes

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjsoncpp.so:devel/jsoncpp
RUN_DEPENDS=	${LOCALBASE}/share/cmake/Modules/CMake.cmake:devel/cmake-modules

MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
MANPAGES_CONFIGURE_ON=	--sphinx-man
.endif

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != "" && !defined(WITH_DEBUG)
INSTALL_TARGET=	install/strip
.endif

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/Source/cmLocalGenerator.cxx \
		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
		${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's,/opt/kde4,${KDE4_PREFIX},g' \
		${WRKSRC}/Modules/FindKDE4.cmake
	@${REINPLACE_CMD} -e 's,/usr/include,${LOCALBASE}/include,' \
		${WRKSRC}/Modules/FindDCMTK.cmake
	@${FIND} ${WRKSRC} -name "*.bak" -delete -o -name "*.orig" -delete

# cmake-gui(1) is installed by devel/cmake-gui. Remove the man page's source to
# prevent it from being built/installed by devel/cmake.
	${RM} ${WRKSRC}/Help/manual/cmake-gui.1.rst

.if !defined(CMAKE_MODULES)
post-install:
	${INSTALL_DATA} ${WRKSRC}/Auxiliary/cmake-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
.endif

.include <bsd.port.post.mk>
