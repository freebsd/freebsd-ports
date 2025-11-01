PORTNAME=	tree-sitter-languages
PORTVERSION=	1.10.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Binary Python wheels for all tree sitter languages
WWW=		https://github.com/grantjenks/py-tree-sitter-languages

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0:devel/py-tree-sitter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tree-sitter>=0:devel/py-tree-sitter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython3 pep517

USE_GITHUB=	yes
# https://github.com/grantjenks/py-tree-sitter-languages/blob/main/repos.txt
GH_TUPLE=	grantjenks:py-tree-sitter-languages:v${PORTVERSION} \
		Azganoth:tree-sitter-lua:6b02dfd:Azganoth_tree_sitter_lua/vendor/tree-sitter-lua \
		MichaHoffmann:tree-sitter-hcl:e135399:MichaHoffmann_tree_sitter_hcl/vendor/tree-sitter-hcl \
		WhatsApp:tree-sitter-erlang:54b6f81:WhatsApp_tree_sitter_erlang/vendor/tree-sitter-erlang \
		Wilfred:tree-sitter-elisp:4b0e4a3:Wilfred_tree_sitter_elisp/vendor/tree-sitter-elisp \
		ZedThree:tree-sitter-fixed-form-fortran:3142d31:ZedThree_tree_sitter_fixed_form_fortran/vendor/tree-sitter-fixed-form-fortran \
		alemuller:tree-sitter-make:a4b9187:alemuller_tree_sitter_make/vendor/tree-sitter-make \
		camdencheek:tree-sitter-dockerfile:25c71d6:camdencheek_tree_sitter_dockerfile/vendor/tree-sitter-dockerfile \
		camdencheek:tree-sitter-go-mod:4a65743:camdencheek_tree_sitter_go_mod/vendor/tree-sitter-go-mod \
		dhcmrlchtdj:tree-sitter-sqlite:993be0a:dhcmrlchtdj_tree_sitter_sqlite/vendor/tree-sitter-sqlite \
		elixir-lang:tree-sitter-elixir:11426c5:elixir_lang_tree_sitter_elixir/vendor/tree-sitter-elixir \
		elm-tooling:tree-sitter-elm:c26afd7:elm_tooling_tree_sitter_elm/vendor/tree-sitter-elm \
		fwcd:tree-sitter-kotlin:0ef8789:fwcd_tree_sitter_kotlin/vendor/tree-sitter-kotlin \
		ganezdragon:tree-sitter-perl:15a6914:ganezdragon_tree_sitter_perl/vendor/tree-sitter-perl \
		ikatyang:tree-sitter-markdown:8b8b77a:ikatyang_tree_sitter_markdown/vendor/tree-sitter-markdown \
		ikatyang:tree-sitter-yaml:0e36bed:ikatyang_tree_sitter_yaml/vendor/tree-sitter-yaml \
		jiyee:tree-sitter-objc:afec0de:jiyee_tree_sitter_objc/vendor/tree-sitter-objc \
		m-novikov:tree-sitter-sql:218b672:m_novikov_tree_sitter_sql/vendor/tree-sitter-sql \
		r-lib:tree-sitter-r:c55f8b4:r_lib_tree_sitter_r/vendor/tree-sitter-r \
		rydesun:tree-sitter-dot:9172307:rydesun_tree_sitter_dot/vendor/tree-sitter-dot \
		slackhq:tree-sitter-hack:fca1e29:slackhq_tree_sitter_hack/vendor/tree-sitter-hack \
		stadelmanma:tree-sitter-fortran:f73d473:stadelmanma_tree_sitter_fortran/vendor/tree-sitter-fortran \
		stsewd:tree-sitter-rst:3ba9eb9:stsewd_tree_sitter_rst/vendor/tree-sitter-rst \
		theHamsta:tree-sitter-commonlisp:c7e8149:theHamsta_tree_sitter_commonlisp/vendor/tree-sitter-commonlisp \
		tree-sitter:tree-sitter-bash:f7239f6:tree_sitter_tree_sitter_bash/vendor/tree-sitter-bash \
		tree-sitter:tree-sitter-c:34f4c7e:tree_sitter_tree_sitter_c/vendor/tree-sitter-c \
		tree-sitter:tree-sitter-c-sharp:dd5e597:tree_sitter_tree_sitter_c_sharp/vendor/tree-sitter-c-sharp \
		tree-sitter:tree-sitter-cpp:a714740:tree_sitter_tree_sitter_cpp/vendor/tree-sitter-cpp \
		tree-sitter:tree-sitter-css:98c7b3d:tree_sitter_tree_sitter_css/vendor/tree-sitter-css \
		tree-sitter:tree-sitter-embedded-template:203f7bd:tree_sitter_tree_sitter_embedded_template/vendor/tree-sitter-embedded-template \
		tree-sitter:tree-sitter-go:ff86c7f:tree_sitter_tree_sitter_go/vendor/tree-sitter-go \
		tree-sitter:tree-sitter-haskell:dd924b8:tree_sitter_tree_sitter_haskell/vendor/tree-sitter-haskell \
		tree-sitter:tree-sitter-html:949b780:tree_sitter_tree_sitter_html/vendor/tree-sitter-html \
		tree-sitter:tree-sitter-java:2b57cd9:tree_sitter_tree_sitter_java/vendor/tree-sitter-java \
		tree-sitter:tree-sitter-javascript:f1e5a09:tree_sitter_tree_sitter_javascript/vendor/tree-sitter-javascript \
		tree-sitter:tree-sitter-jsdoc:d01984d:tree_sitter_tree_sitter_jsdoc/vendor/tree-sitter-jsdoc \
		tree-sitter:tree-sitter-json:3fef30d:tree_sitter_tree_sitter_json/vendor/tree-sitter-json \
		tree-sitter:tree-sitter-julia:0c088d1:tree_sitter_tree_sitter_julia/vendor/tree-sitter-julia \
		tree-sitter:tree-sitter-ocaml:4abfdc1:tree_sitter_tree_sitter_ocaml/vendor/tree-sitter-ocaml \
		tree-sitter:tree-sitter-php:33e3016:tree_sitter_tree_sitter_php/vendor/tree-sitter-php \
		tree-sitter:tree-sitter-python:4bfdd90:tree_sitter_tree_sitter_python/vendor/tree-sitter-python \
		tree-sitter:tree-sitter-ql:bd08702:tree_sitter_tree_sitter_ql/vendor/tree-sitter-ql \
		tree-sitter:tree-sitter-regex:2354482:tree_sitter_tree_sitter_regex/vendor/tree-sitter-regex \
		tree-sitter:tree-sitter-ruby:4d9ad3f:tree_sitter_tree_sitter_ruby/vendor/tree-sitter-ruby \
		tree-sitter:tree-sitter-rust:e0e8b6d:tree_sitter_tree_sitter_rust/vendor/tree-sitter-rust \
		tree-sitter:tree-sitter-scala:45b5ba0:tree_sitter_tree_sitter_scala/vendor/tree-sitter-scala \
		tree-sitter:tree-sitter-toml:342d9be:tree_sitter_tree_sitter_toml/vendor/tree-sitter-toml \
		tree-sitter:tree-sitter-tsq:b665659:tree_sitter_tree_sitter_tsq/vendor/tree-sitter-tsq \
		tree-sitter:tree-sitter-typescript:d847898:tree_sitter_tree_sitter_typescript/vendor/tree-sitter-typescript

post-patch:
	@${MV} ${WRKSRC}/build.py ${WRKSRC}/build_cython.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
