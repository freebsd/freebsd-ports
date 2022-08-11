PORTNAME=	YouCompleteMe
DISTVERSION=	g20220614
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Code-completion engine for Vim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libabsl_strings.so:devel/abseil

RUN_DEPENDS=	vim:editors/vim \
		${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>0:devel/py-watchdog@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang python:3.6+
USE_PYTHON=	flavors
USE_GITHUB=	yes
GH_ACCOUNT=	ycm-core
GH_TAGNAME=	c99f408
GH_TUPLE=	ycm-core:ycmd:d1707c1:ycm/third_party/ycmd

CMAKE_SOURCE_PATH=	${WRKSRC}/third_party/ycmd/cpp

PLIST_SUB=		VIMFILESDIR=share/vim/vimfiles \
			YCMDDIR=share/vim/vimfiles/third_party/ycmd \
			PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

SUB_FILES=		pkg-message pkg-install pkg-deinstall
SUB_LIST=		VIMFILESDIR="${VIMFILESDIR}" \
			FIND="${FIND}"

OPTIONS_DEFINE=		C
OPTIONS_DEFAULT=	C
OPTIONS_SUB=		yes

C_DESC=			C-family Semantic Completion Support

C_CMAKE_ON=		-DPATH_TO_LLVM_ROOT=${LOCALBASE}/llvm${LLVM_DEFAULT}
C_LIB_DEPENDS=		libclang.so:devel/llvm${LLVM_DEFAULT}

VIMFILESDIR=		${PREFIX}/share/vim/vimfiles

CMAKE_ARGS=		${CMAKE_ARGS_PY${PYTHON_MAJOR_VER}} -DUSE_SYSTEM_ABSEIL:BOOL=ON

post-patch:
		${REINPLACE_CMD} "s/'python3'/'${PYTHON_VERSION}'/" \
			${WRKSRC}/python/ycm/paths.py

do-install:
		${MKDIR} ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "autoload doc plugin python" \
			"${STAGEDIR}${VIMFILESDIR}")
		(cd ${WRKSRC}/third_party/ycmd && ${COPYTREE_SHARE} \
			"ycmd CORE_VERSION cpp" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd")
		(cd ${WRKSRC}/third_party/ycmd/third_party && ${COPYTREE_SHARE} \
			"clang generic_server tern_runtime tsserver" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party")
		${RM} -rf ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/cpp/ycm/tests \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/ycmd/tests
		${INSTALL_LIB} ${WRKSRC}/third_party/ycmd/ycm_core.cpython-${PYTHON_SUFFIX}.so \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd

.include <bsd.port.mk>
