# Created by: Richard Gallamore <ultima@freebsd.org>
# $FreeBSD$

PORTNAME=	YouCompleteMe
DISTVERSION=	g20180210
CATEGORIES=	devel

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

USES=		cmake python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	Valloric
GH_TAGNAME=	c2a7b3c
GH_TUPLE=	Valloric:ycmd:aa04988:ycm/third_party/ycmd \
		vheon:JediHTTP:d283a73:ycmd5/third_party/ycmd/third_party/JediHTTP

CMAKE_SOURCE_PATH+=	${WRKSRC}/third_party/ycmd/cpp

SUB_FILES=		pkg-message pkg-install pkg-deinstall
SUB_LIST=		VIMFILESDIR="${VIMFILESDIR}"

OPTIONS_DEFINE=		C GO MONO RUST
OPTIONS_DEFAULT=	C GO MONO RUST
OPTIONS_SUB=		yes

C_DESC=			C-family Semantic Completion Support
GO_DESC=		Go Semantic Completion Support
MONO_DESC=		C\# Semantic Completion Support
RUST_DESC=		Rust Semantic Completion Support

C_CMAKE_ON=		-DPATH_TO_LLVM_ROOT=${LOCALBASE}/llvm40
C_LIB_DEPENDS=		libclang.so:devel/llvm40

GO_RUN_DEPENDS=		gocode:devel/go-gocode \
			godef:devel/go-godef

MONO_RUN_DEPENDS=	${LOCALBASE}/share/omnisharp-server/bin/Release/OmniSharp.exe:devel/omnisharp-server
MONO_VARS=		MONOFILESDIR=${VIMFILESDIR}/third_party/ycmd/third_party/OmniSharpServer

RUST_RUN_DEPENDS=	racerd:devel/racerd

VIMFILESDIR=		${PREFIX}/share/vim/vimfiles

do-install:
		${MKDIR} ${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/third_party
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "autoload doc plugin python" \
			"${STAGEDIR}${VIMFILESDIR}")
		(cd ${WRKSRC}/third_party/ycmd && ${COPYTREE_SHARE} \
			"ycmd CORE_VERSION cpp clang_includes" \
			"${STAGEDIR}${VIMFILESDIR}/third_party/ycmd/${d}")
		${RM} -r ${WRKSRC}/third_party/ycmd/third_party/JediHTTP/vendor
		(cd ${WRKSRC}/third_party/ycmd/third_party && ${COPYTREE_SHARE} \
			"JediHTTP tern_runtime" \
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
