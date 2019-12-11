# Created by: Richard Gallamore <ultima@freebsd.org>
# $FreeBSD$

PORTNAME=	YouCompleteMe
DISTVERSION=	g20191130
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Code-completion engine for Vim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	vim:editors/vim \
		${LOCALBASE}/lib/libboost_thread.so:devel/boost-libs \
		${LOCALBASE}/lib/${PY_BOOST} \
		${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>0:devel/py-frozendict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR} \
		${PY_FUTURES}

USES=		cmake python
USE_PYTHON=	flavors
USE_GITHUB=	yes
GH_ACCOUNT=	ycm-core
GH_TAGNAME=	1386c6b
GH_TUPLE=	ycm-core:ycmd:a374320:ycm/third_party/ycmd \
		ycm-core:regex:cc538bb:ycmd5/third_party/ycmd/third_party/cregex

LLVM_VER=		90

CMAKE_SOURCE_PATH=	${WRKSRC}/third_party/ycmd/cpp

PLIST_SUB=		VIMFILESDIR=share/vim/vimfiles \
			YCMDDIR=share/vim/vimfiles/third_party/ycmd \
			PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

SUB_FILES=		pkg-message pkg-install pkg-deinstall
SUB_LIST=		VIMFILESDIR="${VIMFILESDIR}" \
			FIND="${FIND}"

OPTIONS_DEFINE=		C REGEX
OPTIONS_DEFAULT=	C REGEX
OPTIONS_SUB=		yes

C_DESC=			C-family Semantic Completion Support

C_CMAKE_ON=		-DPATH_TO_LLVM_ROOT=${LOCALBASE}/llvm${LLVM_VER}
C_LIB_DEPENDS=		libclang.so:devel/llvm${LLVM_VER}

VIMFILESDIR=		${PREFIX}/share/vim/vimfiles

CMAKE_ARGS_PY3=		-DUSE_PYTHON2:BOOL=OFF
CMAKE_ARGS=		${CMAKE_ARGS_PY${PYTHON_MAJOR_VER}}

post-patch-REGEX-on:
		${PRINTF} "add_subdirectory(../third_party/cregex ${WRKDIR}/.build-regex)" \
			>>${WRKSRC}/third_party/ycmd/cpp/CMakeLists.txt

do-install:
		${MKDIR} ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "autoload doc plugin python" \
			"${STAGEDIR}${VIMFILESDIR}")
		(cd ${WRKSRC}/third_party/ycmd && ${COPYTREE_SHARE} \
			"ycmd CORE_VERSION cpp" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd")
		(cd ${WRKSRC}/third_party/ycmd/third_party && ${COPYTREE_SHARE} \
			"clang cregex tern_runtime" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party")
		${RM} -rf ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/cpp/ycm/tests \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/ycmd/tests
		${INSTALL_LIB} ${WRKSRC}/third_party/ycmd/ycm_core.so \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd

do-install-REGEX-on:
		(cd ${WRKSRC}/third_party/ycmd/third_party && ${COPYTREE_SHARE} \
			"cregex" "${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party")
		${INSTALL_LIB} ${WRKSRC}/third_party/ycmd/third_party/cregex/regex_${PYTHON_MAJOR_VER}/_regex.so \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party/cregex/regex_${PYTHON_MAJOR_VER}

.include <bsd.port.mk>
