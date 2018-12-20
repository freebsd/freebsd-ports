# Created by: Kyle Martin <mkm@ieee.org>
# $FreeBSD$

PORTNAME=	cmake
# Remember to update devel/cmake-doc and devel/cmake-gui as well.
DISTVERSION=	3.13.2
CATEGORIES=	devel
MASTER_SITES=	https://www.cmake.org/files/v${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform Makefile generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjsoncpp.so:devel/jsoncpp \
		libuv.so:devel/libuv \
		librhash.so:security/rhash

USES=		compiler:c++11-lang ncurses

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MAKE=make
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--system-libs \
		--parallel=${MAKE_JOBS_NUMBER} \
		--init="${WRKSRC}/InitialCache.cmake"

OPTIONS_DEFINE=	DOCS MANPAGES CPACK
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_USES=		python:env
MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
MANPAGES_CONFIGURE_ON=	--sphinx-man

CPACK_DESC=		Enable FreeBSD generator in CPack (experimental)
CPACK_LIB_DEPENDS=	libpkg.so:ports-mgmt/pkg
CPACK_USES_OFF=		libarchive
# When CPACK is on, uses base libarchive and won't pass stage-qa

CONFLICTS_INSTALL=	cmake-modules-*

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != "" && !defined(WITH_DEBUG)
INSTALL_TARGET=	install/strip
.endif

# Before running configure, substitute in the values of options
# for the build. CMake's configure doesn't accept --with-foo
# or similar options: it expects them to be set in CMake-style
# syntax in the initial cache.
pre-configure:
	@${CP} "${FILESDIR}/InitialCache.cmake" "${WRKSRC}/InitialCache.cmake"

pre-configure-CPACK-on:
	@${REINPLACE_CMD} \
		-e 's/@@CPACK_OPTION_VALUE@@/ON/' \
		-e 's/@@CPACK_OPTION_COMMENT@@//' \
		"${WRKSRC}/InitialCache.cmake"

pre-configure-CPACK-off:
	@${REINPLACE_CMD} \
		-e 's/@@CPACK_OPTION_VALUE@@/OFF/' \
		-e 's/@@CPACK_OPTION_COMMENT@@/# /' \
		"${WRKSRC}/InitialCache.cmake"

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/Source/cmLocalGenerator.cxx \
		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
		${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's,/opt/kde4,${PREFIX},g' \
		${WRKSRC}/Modules/FindKDE4.cmake
	@${REINPLACE_CMD} -e 's,/usr/include,${LOCALBASE}/include,' \
		${WRKSRC}/Modules/FindDCMTK.cmake
	@${FIND} ${WRKSRC} -name "*.bak" -delete -o -name "*.orig" -delete

# cmake-gui(1) is installed by devel/cmake-gui. Remove the man page's source to
# prevent it from being built/installed by devel/cmake.
	${RM} ${WRKSRC}/Help/manual/cmake-gui.1.rst

post-install:
	${INSTALL_DATA} ${WRKSRC}/Auxiliary/cmake-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	# The .NoDartCoverage is supposed to suppress testing in the
	# source directories, but gets accidentally installed.
	@${FIND} ${STAGEDIR}${PREFIX} -name ".NoDartCoverage" -delete

.include <bsd.port.post.mk>
