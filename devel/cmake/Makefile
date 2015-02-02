# Created by: Kyle Martin <mkm@ieee.org>
# $FreeBSD$

PORTNAME=	cmake
PORTVERSION=	3.1.1
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v3.1/

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Cross-platform Makefile generator

LICENSE=	BSD3CLAUSE

USE_KDE4=	# env
CONFIGURE_ENV=	MAKE=make
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--sphinx-man \
		--system-libs \
		--parallel=${MAKE_JOBS_NUMBER} \
		--init="${PATCHDIR}/InitialCache.cmake"

.if !defined(CMAKE_MODULES)
OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
HAS_CONFIGURE=	yes

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${LOCALBASE}/share/cmake/Modules/CMake.cmake:${PORTSDIR}/devel/cmake-modules
.endif

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != "" && !defined(WITH_DEBUG)
INSTALL_TARGET=	install/strip
.endif

.if !defined(CMAKE_MODULES)
# CMake >= 3.1.0 needs libarchive3 because it calls
# archive_entry_copy_sourcepath_w and archive_write_set_format_7zip.
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000009
LIB_DEPENDS+=	libarchive.so.13:${PORTSDIR}/archivers/libarchive
.endif  # ${OPSYS} == FreeBSD && ${OSVERSION} < 1000009
.endif  # !defined(CMAKE_MODULES)

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
