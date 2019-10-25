# Created by: Richard Gallamore <ultima@freebsd.org>
# $FreeBSD$

PORTNAME=	YouCompleteMe
DISTVERSION=	g20190314
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Code-completion engine for Vim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	vim:editors/vim \
		${LOCALBASE}/lib/libboost_thread.so:devel/boost-libs \
		${LOCALBASE}/lib/${PY_BOOST} \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>0:devel/py-frozendict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR}

USES=		cmake python
USE_PYTHON=	flavors
USE_GITHUB=	yes
GH_ACCOUNT=	Valloric
GH_TAGNAME=	299f8e4
GH_TUPLE=	Valloric:ycmd:d0eba90:ycm/third_party/ycmd \
		micbou:regex:d2ef9c4:ycmd5/third_party/ycmd/third_party/cregex

LLVM_VER=		70

CMAKE_SOURCE_PATH+=	${WRKSRC}/third_party/ycmd/cpp

PLIST_SUB=		VIMFILESDIR=share/vim/vimfiles \
			YCMDDIR=share/vim/vimfiles/third_party/ycmd

SUB_FILES=		pkg-message pkg-install pkg-deinstall
SUB_LIST=		VIMFILESDIR="${VIMFILESDIR}" \
			FIND="${FIND}"

OPTIONS_DEFINE=		C MONO RUST
OPTIONS_DEFAULT=	C MONO RUST
OPTIONS_SUB=		yes

C_DESC=			C-family Semantic Completion Support
MONO_DESC=		C\# Semantic Completion Support
RUST_DESC=		Rust Semantic Completion Support

C_CMAKE_ON=		-DPATH_TO_LLVM_ROOT=${LOCALBASE}/llvm${LLVM_VER}
C_LIB_DEPENDS=		libclang.so:devel/llvm${LLVM_VER}

MONO_RUN_DEPENDS=	${LOCALBASE}/share/omnisharp-server/bin/Release/OmniSharp.exe:devel/omnisharp-server
MONO_VARS=		MONOFILESDIR=${VIMFILESDIR}/third_party/ycmd/third_party/OmniSharpServer

RUST_RUN_DEPENDS=	racerd:devel/racerd

VIMFILESDIR=		${PREFIX}/share/vim/vimfiles

CMAKE_ARGS_PY3=		-DUSE_PYTHON2:BOOL=OFF
CMAKE_ARGS=		${CMAKE_ARGS_PY${PYTHON_MAJOR_VER}}

do-install:
		${MKDIR} ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "autoload doc plugin python" \
			"${STAGEDIR}${VIMFILESDIR}")
		(cd ${WRKSRC}/third_party/ycmd && ${COPYTREE_SHARE} \
			"ycmd CORE_VERSION cpp clang_includes" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/${d}")
		(cd ${WRKSRC}/third_party/ycmd/third_party && ${COPYTREE_SHARE} \
			"cregex tern_runtime" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party")
		${RM} -rf ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/cpp/ycm/tests \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/ycmd/tests
		${INSTALL_LIB} ${WRKSRC}/third_party/ycmd/ycm_core.so \
			${STAGEDIR}${VIMFILESDIR}/third_party/ycmd

do-install-MONO-on:
		${MKDIR} ${STAGEDIR}${MONOFILESDIR}/OmniSharp/bin
		${RLN} ${PREFIX}/share/omnisharp-server/bin/Release \
			${STAGEDIR}${MONOFILESDIR}/OmniSharp/bin/Release

.include <bsd.port.mk>
