PORTNAME=	helix
DISTVERSION=	22.03
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Post-modern modal text editor

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

CONFLICTS_INSTALL=	shx

USE_GITHUB=	yes
GH_ACCOUNT=	helix-editor
GH_TUPLE=	\
		ikatyang:tree-sitter-toml:7cff70b:tree_sitter_toml/runtime/grammars/sources/toml \
		tree-sitter:tree-sitter-bash:a8eb5cb:tree_sitter_bash/runtime/grammars/sources/bash \
		tree-sitter:tree-sitter-c-sharp:53a65a9:tree_sitter_c_sharp/runtime/grammars/sources/c-sharp \
		tree-sitter:tree-sitter-c:f05e279:tree_sitter_c/runtime/grammars/sources/c \
		uyha:tree-sitter-cmake:f6616f1:tree_sitter_cmake/runtime/grammars/sources/cmake \
		stsewd:tree-sitter-comment:5dd3c62:tree_sitter_comment/runtime/grammars/sources/comment \
		tree-sitter:tree-sitter-cpp:e8dcc9d:tree_sitter_cpp/runtime/grammars/sources/cpp \
		tree-sitter:tree-sitter-css:94e1023:tree_sitter_css/runtime/grammars/sources/css \
		UserNobody14:tree-sitter-dart:6a25376:tree_sitter_dart/runtime/grammars/sources/dart \
		camdencheek:tree-sitter-dockerfile:7af32bc:tree_sitter_dockerfile/runtime/grammars/sources/dockerfile \
		elixir-lang:tree-sitter-elixir:f5d7bda:tree_sitter_elixir/runtime/grammars/sources/elixir \
		elm-tooling:tree-sitter-elm:bd50ccf:tree_sitter_elm/runtime/grammars/sources/elm \
		the-mikedavis:tree-sitter-erlang:86985bd:tree_sitter_erlang/runtime/grammars/sources/erlang \
		ram02z:tree-sitter-fish:04e54ab:tree_sitter_fish/runtime/grammars/sources/fish \
		the-mikedavis:tree-sitter-git-commit:7ae23de:tree_sitter_git_commit/runtime/grammars/sources/git-commit \
		the-mikedavis:tree-sitter-git-config:0e4f0ba:tree_sitter_git_config/runtime/grammars/sources/git-config \
		the-mikedavis:tree-sitter-diff:c12e6ec:tree_sitter_git_diff/runtime/grammars/sources/git-diff \
		the-mikedavis:tree-sitter-git-rebase:332dc52:tree_sitter_git_rebase/runtime/grammars/sources/git-rebase \
		theHamsta:tree-sitter-glsl:88408ff:tree_sitter_glsl/runtime/grammars/sources/glsl \
		tree-sitter:tree-sitter-go:0fa917a:tree_sitter_go/runtime/grammars/sources/go \
		bkegley:tree-sitter-graphql:5e66e96:tree_sitter_graphql/runtime/grammars/sources/graphql \
		tree-sitter:tree-sitter-haskell:b6ec26f:tree_sitter_haskell/runtime/grammars/sources/haskell \
		MichaHoffmann:tree-sitter-hcl:3cb7fc2:tree_sitter_hcl/runtime/grammars/sources/hcl \
		tree-sitter:tree-sitter-html:d93af48:tree_sitter_html/runtime/grammars/sources/html \
		elixir-lang:tree-sitter-iex:39f20bb:tree_sitter_iex/runtime/grammars/sources/iex \
		tree-sitter:tree-sitter-java:bd6186c:tree_sitter_java/runtime/grammars/sources/java \
		tree-sitter:tree-sitter-javascript:4a95461:tree_sitter_javascript/runtime/grammars/sources/javascript \
		tree-sitter:tree-sitter-json:65bceef:tree_sitter_json/runtime/grammars/sources/json \
		tree-sitter:tree-sitter-julia:12ea597:tree_sitter_julia/runtime/grammars/sources/julia \
		fwcd:tree-sitter-kotlin:a4f71eb:tree_sitter_kotlin/runtime/grammars/sources/kotlin \
		latex-lsp:tree-sitter-latex:7f72066:tree_sitter_latex/runtime/grammars/sources/latex \
		Julian:tree-sitter-lean:d984261:tree_sitter_lean/runtime/grammars/sources/lean \
		cbarrete:tree-sitter-ledger:0cdeb0e:tree_sitter_ledger/runtime/grammars/sources/ledger \
		Flakebi:tree-sitter-llvm-mir:06fabca:tree_sitter_llvm_mir/runtime/grammars/sources/llvm-mir \
		benwilliamgraham:tree-sitter-llvm:3b21392:tree_sitter_llvm/runtime/grammars/sources/llvm \
		nvim-treesitter:tree-sitter-lua:6f5d401:tree_sitter_lua/runtime/grammars/sources/lua \
		alemuller:tree-sitter-make:a4b9187:tree_sitter_make/runtime/grammars/sources/make \
		MDeiml:tree-sitter-markdown:ad8c329:tree_sitter_markdown/runtime/grammars/sources/markdown \
		cstrahan:tree-sitter-nix:50f38ce:tree_sitter_nix/runtime/grammars/sources/nix \
		tree-sitter:tree-sitter-ocaml:23d419b:tree_sitter_ocaml/runtime/grammars/sources/ocaml \
		milisims:tree-sitter-org:1c3eb53:tree_sitter_org/runtime/grammars/sources/org \
		ganezdragon:tree-sitter-perl:0ac2c6d:tree_sitter_perl/runtime/grammars/sources/perl \
		tree-sitter:tree-sitter-php:57f8554:tree_sitter_php/runtime/grammars/sources/php \
		yusdacra:tree-sitter-protobuf:19c211a:tree_sitter_protobuf/runtime/grammars/sources/protobuf \
		tree-sitter:tree-sitter-python:d6210ce:tree_sitter_python/runtime/grammars/sources/python \
		tree-sitter:tree-sitter-regex:e1cfca3:tree_sitter_regex/runtime/grammars/sources/regex \
		jaredramirez:tree-sitter-rescript:4cd7ba9:tree_sitter_rescript/runtime/grammars/sources/rescript \
		tree-sitter:tree-sitter-ruby:dfff673:tree_sitter_ruby/runtime/grammars/sources/ruby \
		tree-sitter:tree-sitter-rust:a360da0:tree_sitter_rust/runtime/grammars/sources/rust \
		tree-sitter:tree-sitter-scala:0a3dd53:tree_sitter_scala/runtime/grammars/sources/scala \
		slinlee:tree-sitter-solidity:f3a0022:tree_sitter_solidity/runtime/grammars/sources/solidity \
		Himujjal:tree-sitter-svelte:349a598:tree_sitter_svelte/runtime/grammars/sources/svelte \
		Flakebi:tree-sitter-tablegen:568dd8a:tree_sitter_tablegen/runtime/grammars/sources/tablegen \
		tree-sitter:tree-sitter-tsq:b665659:tree_sitter_tsq/runtime/grammars/sources/tsq \
		eirabben:tree-sitter-twig:b744418:tree_sitter_twig/runtime/grammars/sources/twig \
		tree-sitter:tree-sitter-typescript:3e897ea:tree_sitter_typescript/runtime/grammars/sources/typescript \
		ikatyang:tree-sitter-vue:91fe275:tree_sitter_vue/runtime/grammars/sources/vue \
		szebniok:tree-sitter-wgsl:f00ff52:tree_sitter_wgsl/runtime/grammars/sources/wgsl \
		ikatyang:tree-sitter-yaml:0e36bed:tree_sitter_yaml/runtime/grammars/sources/yaml \
		maxxnino:tree-sitter-zig:93331b8:tree_sitter_zig/runtime/grammars/sources/zig

CARGO_CARGOTOML=	${WRKSRC}/helix-term/Cargo.toml
CARGO_INSTALL_PATH=	./helix-term
CARGO_CRATES=	aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		arc-swap-1.5.0 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bytecount-0.6.2 \
		bytes-1.1.0 \
		cassowary-0.3.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chardetng-0.1.17 \
		chrono-0.4.19 \
		clipboard-win-4.4.1 \
		content_inspector-0.2.4 \
		crossbeam-utils-0.8.8 \
		crossterm-0.23.1 \
		crossterm_winapi-0.9.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		encoding_rs-0.8.30 \
		encoding_rs_io-0.1.7 \
		error-code-2.3.1 \
		etcetera-0.3.2 \
		fern-0.6.0 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		fuzzy-matcher-0.3.7 \
		getrandom-0.2.5 \
		globset-0.4.8 \
		grep-matcher-0.1.5 \
		grep-regex-0.1.9 \
		grep-searcher-0.1.8 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		ignore-0.4.18 \
		itoa-1.0.1 \
		jsonrpc-core-18.0.0 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		libloading-0.7.3 \
		lock_api-0.4.6 \
		log-0.4.16 \
		lsp-types-0.92.1 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memmap2-0.3.1 \
		mio-0.7.14 \
		mio-0.8.1 \
		miow-0.3.7 \
		ntapi-0.3.7 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		parking_lot-0.12.0 \
		parking_lot_core-0.9.1 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.36 \
		pulldown-cmark-0.9.1 \
		quickcheck-1.0.3 \
		quote-1.0.15 \
		rand-0.8.5 \
		rand_core-0.6.3 \
		redox_syscall-0.2.11 \
		redox_users-0.4.0 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		retain_mut-0.1.7 \
		ropey-1.4.1 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serde_repr-0.1.7 \
		signal-hook-0.3.13 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		signal-hook-tokio-0.3.1 \
		similar-2.1.0 \
		slab-0.4.5 \
		slotmap-1.0.6 \
		smallvec-1.8.0 \
		smartstring-1.0.1 \
		socket2-0.4.4 \
		static_assertions-1.1.0 \
		str-buf-1.0.5 \
		str_indices-0.3.1 \
		syn-1.0.89 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.4 \
		threadpool-1.8.1 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.17.0 \
		tokio-macros-1.7.0 \
		tokio-stream-0.1.8 \
		toml-0.5.8 \
		tree-sitter-0.20.6 \
		unicase-2.6.0 \
		unicode-bidi-0.3.7 \
		unicode-general-category-0.5.1 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-4.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.32.0 \
		windows_aarch64_msvc-0.32.0 \
		windows_i686_gnu-0.32.0 \
		windows_i686_msvc-0.32.0 \
		windows_x86_64_gnu-0.32.0 \
		windows_x86_64_msvc-0.32.0

post-extract:
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a typescript tsx
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a ocaml ocaml-interface

post-patch:
	${GREP} -F -Rl '%%DATADIR%%' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},'

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/runtime/grammars
.for DIR in queries themes
	cd ${WRKSRC}/runtime && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${DATADIR}/runtime
.endfor
	${INSTALL_DATA} ${WRKSRC}/runtime/tutor.txt ${STAGEDIR}${DATADIR}/runtime/tutor.txt
	${FIND} ${WRKSRC}/runtime/grammars -maxdepth 1 -type f -name '*.so' \
		-exec ${INSTALL_LIB} {} ${STAGEDIR}${DATADIR}/runtime/grammars \;

.include <bsd.port.mk>
