PORTNAME=	helix
DISTVERSION=	23.05
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://git.sr.ht/~ecmma/tree-sitter-hare/archive/:treesitterhare \
		https://raw.githubusercontent.com/tree-sitter/tree-sitter-javascript/${TREE_SITTER_JSHIGH_REV}/queries/highlights.scm?file=/:jshigh \
		https://raw.githubusercontent.com/tree-sitter/tree-sitter-typescript/${TREE_SITTER_TSHIGH_REV}/queries/highlights.scm?file=/:tshigh
DISTFILES=	${TREE_SITTER_HARE_REV}.tar.gz:treesitterhare \
		${TREE_SITTER_JSHIGH_REV}-js-highlights.scm:jshigh \
		${TREE_SITTER_TSHIGH_REV}-ts-highlights.scm:tshigh
EXTRACT_ONLY=	${DISTFILES:N*\:*high:C/:[^:]+$//}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Post-modern modal text editor
WWW=		https://helix-editor.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

CONFLICTS_INSTALL=	shx

USE_GITHUB=	yes
GH_ACCOUNT=	helix-editor
GH_TUPLE=	\
		virchau13:tree-sitter-astro:5f5c3e73:virchau13_tree_sitter_astro/runtime/grammars/sources/astro \
		Beaglefoot:tree-sitter-awk:a799bc5d:Beaglefoot_tree_sitter_awk/runtime/grammars/sources/awk \
		tree-sitter:tree-sitter-bash:275effdf:tree_sitter_tree_sitter_bash/runtime/grammars/sources/bash \
		vito:tree-sitter-bass:501133e2:vito_tree_sitter_bass/runtime/grammars/sources/bass \
		polarmutex:tree-sitter-beancount:4cbd1f09:polarmutex_tree_sitter_beancount/runtime/grammars/sources/beancount \
		latex-lsp:tree-sitter-bibtex:ccfd77db:latex_lsp_tree_sitter_bibtex/runtime/grammars/sources/bibtex \
		the-mikedavis:tree-sitter-bicep:d8e097fc:the_mikedavis_tree_sitter_bicep/runtime/grammars/sources/bicep \
		tree-sitter:tree-sitter-c:7175a6dd:tree_sitter_tree_sitter_c/runtime/grammars/sources/c \
		archseer:tree-sitter-cairo:b249662a:archseer_tree_sitter_cairo/runtime/grammars/sources/cairo \
		amaanq:tree-sitter-capnp:fc6e2add:amaanq_tree_sitter_capnp/runtime/grammars/sources/capnp \
		sogaiu:tree-sitter-clojure:e57c569a:sogaiu_tree_sitter_clojure/runtime/grammars/sources/clojure \
		uyha:tree-sitter-cmake:6e51463e:uyha_tree_sitter_cmake/runtime/grammars/sources/cmake \
		stsewd:tree-sitter-comment:5dd3c62f:stsewd_tree_sitter_comment/runtime/grammars/sources/comment \
		fvacek:tree-sitter-cpon:0d01fcda:fvacek_tree_sitter_cpon/runtime/grammars/sources/cpon \
		tree-sitter:tree-sitter-cpp:2d2c4aee:tree_sitter_tree_sitter_cpp/runtime/grammars/sources/cpp \
		tree-sitter:tree-sitter-c-sharp:5b60f995:tree_sitter_tree_sitter_c_sharp/runtime/grammars/sources/c-sharp \
		tree-sitter:tree-sitter-css:769203d0:tree_sitter_tree_sitter_css/runtime/grammars/sources/css \
		eonpatapon:tree-sitter-cue:61843e3b:eonpatapon_tree_sitter_cue/runtime/grammars/sources/cue \
		gdamore:tree-sitter-d:601c4a1e:gdamore_tree_sitter_d/runtime/grammars/sources/d \
		UserNobody14:tree-sitter-dart:2d7f6665:UserNobody14_tree_sitter_dart/runtime/grammars/sources/dart \
		joelspadin:tree-sitter-devicetree:877adbfa:joelspadin_tree_sitter_devicetree/runtime/grammars/sources/devicetree \
		jbellerb:tree-sitter-dhall:affb6ee3:jbellerb_tree_sitter_dhall/runtime/grammars/sources/dhall \
		the-mikedavis:tree-sitter-diff:fd74c78f:the_mikedavis_tree_sitter_diff/runtime/grammars/sources/diff \
		camdencheek:tree-sitter-dockerfile:8ee3a0f7:camdencheek_tree_sitter_dockerfile/runtime/grammars/sources/dockerfile \
		rydesun:tree-sitter-dot:91723074:rydesun_tree_sitter_dot/runtime/grammars/sources/dot \
		KMikeeU:tree-sitter-dtd:6116becb:KMikeeU_tree_sitter_dtd/runtime/grammars/sources/dtd \
		the-mikedavis:tree-sitter-edoc:74774af7:the_mikedavis_tree_sitter_edoc/runtime/grammars/sources/edoc \
		connorlay:tree-sitter-eex:f742f2fe:connorlay_tree_sitter_eex/runtime/grammars/sources/eex \
		elixir-lang:tree-sitter-elixir:b20eaa75:elixir_lang_tree_sitter_elixir/runtime/grammars/sources/elixir \
		elm-tooling:tree-sitter-elm:df4cb639:elm_tooling_tree_sitter_elm/runtime/grammars/sources/elm \
		ckafi:tree-sitter-elvish:e50787ca:ckafi_tree_sitter_elvish/runtime/grammars/sources/elvish \
		tree-sitter:tree-sitter-embedded-template:d21df11b:tree_sitter_tree_sitter_embedded_template/runtime/grammars/sources/embedded-template \
		the-mikedavis:tree-sitter-erlang:ce0ed253:the_mikedavis_tree_sitter_erlang/runtime/grammars/sources/erlang \
		greym0uth:tree-sitter-esdl:b840c8a8:greym0uth_tree_sitter_esdl/runtime/grammars/sources/esdl \
		ram02z:tree-sitter-fish:84436cf2:ram02z_tree_sitter_fish/runtime/grammars/sources/fish \
		stadelmanma:tree-sitter-fortran:f0f2f100:stadelmanma_tree_sitter_fortran/runtime/grammars/sources/fortran \
		PrestonKnopp:tree-sitter-gdscript:a4b57cc3:PrestonKnopp_tree_sitter_gdscript/runtime/grammars/sources/gdscript \
		mtoohey31:tree-sitter-gitattributes:3dd50808:mtoohey31_tree_sitter_gitattributes/runtime/grammars/sources/gitattributes \
		the-mikedavis:tree-sitter-git-commit:db88cffa:the_mikedavis_tree_sitter_git_commit/runtime/grammars/sources/git-commit \
		the-mikedavis:tree-sitter-git-config:0e4f0baf:the_mikedavis_tree_sitter_git_config/runtime/grammars/sources/git-config \
		shunsambongi:tree-sitter-gitignore:f4685bf1:shunsambongi_tree_sitter_gitignore/runtime/grammars/sources/gitignore \
		the-mikedavis:tree-sitter-git-rebase:d8a4207e:the_mikedavis_tree_sitter_git_rebase/runtime/grammars/sources/git-rebase \
		gleam-lang:tree-sitter-gleam:ae79782c:gleam_lang_tree_sitter_gleam/runtime/grammars/sources/gleam \
		theHamsta:tree-sitter-glsl:88408ffc:theHamsta_tree_sitter_glsl/runtime/grammars/sources/glsl \
		tree-sitter:tree-sitter-go:64457ea6:tree_sitter_tree_sitter_go/runtime/grammars/sources/go \
		PrestonKnopp:tree-sitter-godot-resource:b6ef0768:PrestonKnopp_tree_sitter_godot_resource/runtime/grammars/sources/godot-resource \
		camdencheek:tree-sitter-go-mod:e8f51f8e:camdencheek_tree_sitter_go_mod/runtime/grammars/sources/gomod \
		dannylongeuay:tree-sitter-go-template:395a33e0:dannylongeuay_tree_sitter_go_template/runtime/grammars/sources/gotmpl \
		omertuc:tree-sitter-go-work:6dd9dd79:omertuc_tree_sitter_go_work/runtime/grammars/sources/gowork \
		bkegley:tree-sitter-graphql:5e66e961:bkegley_tree_sitter_graphql/runtime/grammars/sources/graphql \
		tree-sitter:tree-sitter-haskell:98fc7f59:tree_sitter_tree_sitter_haskell/runtime/grammars/sources/haskell \
		MichaHoffmann:tree-sitter-hcl:3cb7fc28:MichaHoffmann_tree_sitter_hcl/runtime/grammars/sources/hcl \
		phoenixframework:tree-sitter-heex:2e1348c3:phoenixframework_tree_sitter_heex/runtime/grammars/sources/heex \
		ath3:tree-sitter-hosts:301b9379:ath3_tree_sitter_hosts/runtime/grammars/sources/hosts \
		tree-sitter:tree-sitter-html:29f53d8f:tree_sitter_tree_sitter_html/runtime/grammars/sources/html \
		pfeiferj:tree-sitter-hurl:264c4206:pfeiferj_tree_sitter_hurl/runtime/grammars/sources/hurl \
		elixir-lang:tree-sitter-iex:39f20bb5:elixir_lang_tree_sitter_iex/runtime/grammars/sources/iex \
		justinmk:tree-sitter-ini:4d247fb8:justinmk_tree_sitter_ini/runtime/grammars/sources/ini \
		tree-sitter:tree-sitter-java:09d650de:tree_sitter_tree_sitter_java/runtime/grammars/sources/java \
		tree-sitter:tree-sitter-javascript:4a95461c:tree_sitter_tree_sitter_javascript/runtime/grammars/sources/javascript \
		tree-sitter:tree-sitter-jsdoc:189a6a48:tree_sitter_tree_sitter_jsdoc/runtime/grammars/sources/jsdoc \
		tree-sitter:tree-sitter-json:73076754:tree_sitter_tree_sitter_json/runtime/grammars/sources/json \
		sourcegraph:tree-sitter-jsonnet:0475a501:sourcegraph_tree_sitter_jsonnet/runtime/grammars/sources/jsonnet \
		tree-sitter:tree-sitter-julia:8fb38abf:tree_sitter_tree_sitter_julia/runtime/grammars/sources/julia \
		IndianBoy42:tree-sitter-just:8af0aab7:IndianBoy42_tree_sitter_just/runtime/grammars/sources/just \
		Unoqwy:tree-sitter-kdl:e1cd292c:Unoqwy_tree_sitter_kdl/runtime/grammars/sources/kdl \
		fwcd:tree-sitter-kotlin:a4f71eb9:fwcd_tree_sitter_kotlin/runtime/grammars/sources/kotlin \
		latex-lsp:tree-sitter-latex:8c75e93c:latex_lsp_tree_sitter_latex/runtime/grammars/sources/latex \
		Julian:tree-sitter-lean:d9842610:Julian_tree_sitter_lean/runtime/grammars/sources/lean \
		cbarrete:tree-sitter-ledger:1f864fb2:cbarrete_tree_sitter_ledger/runtime/grammars/sources/ledger \
		benwilliamgraham:tree-sitter-llvm:3b213925:benwilliamgraham_tree_sitter_llvm/runtime/grammars/sources/llvm \
		Flakebi:tree-sitter-llvm-mir:06fabca1:Flakebi_tree_sitter_llvm_mir/runtime/grammars/sources/llvm-mir \
		MunifTanjim:tree-sitter-lua:887dfd4e:MunifTanjim_tree_sitter_lua/runtime/grammars/sources/lua \
		alemuller:tree-sitter-make:a4b91874:alemuller_tree_sitter_make/runtime/grammars/sources/make \
		markdoc-extra:tree-sitter-markdoc:5ffe71b2:markdoc_extra_tree_sitter_markdoc/runtime/grammars/sources/markdoc \
		MDeiml:tree-sitter-markdown:fa6bfd51:MDeiml_tree_sitter_markdown/runtime/grammars/sources/markdown \
		mstanciu552:tree-sitter-matlab:2d5d3d51:mstanciu552_tree_sitter_matlab/runtime/grammars/sources/matlab \
		monaqa:tree-sitter-mermaid:d787c662:monaqa_tree_sitter_mermaid/runtime/grammars/sources/mermaid \
		staysail:tree-sitter-meson:32a83e8f:staysail_tree_sitter_meson/runtime/grammars/sources/meson \
		naclsn:tree-sitter-nasm:a0db15db:naclsn_tree_sitter_nasm/runtime/grammars/sources/nasm \
		nickel-lang:tree-sitter-nickel:9d83db40:nickel_lang_tree_sitter_nickel/runtime/grammars/sources/nickel \
		aMOPel:tree-sitter-nim:240239b2:aMOPel_tree_sitter_nim/runtime/grammars/sources/nim \
		nix-community:tree-sitter-nix:1b69cf1f:nix_community_tree_sitter_nix/runtime/grammars/sources/nix \
		LhKipp:tree-sitter-nu:eb95bdac:LhKipp_tree_sitter_nu/runtime/grammars/sources/nu \
		tree-sitter:tree-sitter-ocaml:23d419ba:tree_sitter_tree_sitter_ocaml/runtime/grammars/sources/ocaml \
		ap29600:tree-sitter-odin:b219207e:ap29600_tree_sitter_odin/runtime/grammars/sources/odin \
		lefp:tree-sitter-opencl:8e1d24a5:lefp_tree_sitter_opencl/runtime/grammars/sources/opencl \
		bollian:tree-sitter-openscad:5c3ce93d:bollian_tree_sitter_openscad/runtime/grammars/sources/openscad \
		milisims:tree-sitter-org:698bb1a3:milisims_tree_sitter_org/runtime/grammars/sources/org \
		Isopod:tree-sitter-pascal:2fd40f47:Isopod_tree_sitter_pascal/runtime/grammars/sources/pascal \
		ath3:tree-sitter-passwd:20239395:ath3_tree_sitter_passwd/runtime/grammars/sources/passwd \
		mtoohey31:tree-sitter-pem:be67a433:mtoohey31_tree_sitter_pem/runtime/grammars/sources/pem \
		ganezdragon:tree-sitter-perl:0ac2c6da:ganezdragon_tree_sitter_perl/runtime/grammars/sources/perl \
		tree-sitter:tree-sitter-php:f860e598:tree_sitter_tree_sitter_php/runtime/grammars/sources/php \
		erasin:tree-sitter-po:417cee9a:erasin_tree_sitter_po/runtime/grammars/sources/po \
		mfelsche:tree-sitter-ponylang:ef66b151:mfelsche_tree_sitter_ponylang/runtime/grammars/sources/ponylang \
		victorhqc:tree-sitter-prisma:eca2596a:victorhqc_tree_sitter_prisma/runtime/grammars/sources/prisma \
		yusdacra:tree-sitter-protobuf:19c211a0:yusdacra_tree_sitter_protobuf/runtime/grammars/sources/protobuf \
		PRQL:tree-sitter-prql:3f27cac4:PRQL_tree_sitter_prql/runtime/grammars/sources/prql \
		tree-sitter:tree-sitter-python:de221ecc:tree_sitter_tree_sitter_python/runtime/grammars/sources/python \
		yuja:tree-sitter-qmljs:0b2b25bc:yuja_tree_sitter_qmljs/runtime/grammars/sources/qmljs \
		r-lib:tree-sitter-r:cc04302e:r_lib_tree_sitter_r/runtime/grammars/sources/r \
		tree-sitter:tree-sitter-regex:e1cfca3c:tree_sitter_tree_sitter_regex/runtime/grammars/sources/regex \
		FallenAngel97:tree-sitter-rego:b2667c97:FallenAngel97_tree_sitter_rego/runtime/grammars/sources/rego \
		jaredramirez:tree-sitter-rescript:65609807:jaredramirez_tree_sitter_rescript/runtime/grammars/sources/rescript \
		Hubro:tree-sitter-robot:f1142bfa:Hubro_tree_sitter_robot/runtime/grammars/sources/robot \
		stsewd:tree-sitter-rst:25e63288:stsewd_tree_sitter_rst/runtime/grammars/sources/rst \
		tree-sitter:tree-sitter-ruby:206c7077:tree_sitter_tree_sitter_ruby/runtime/grammars/sources/ruby \
		tree-sitter:tree-sitter-rust:0431a2c6:tree_sitter_tree_sitter_rust/runtime/grammars/sources/rust \
		tree-sitter:tree-sitter-scala:f6bbf35d:tree_sitter_tree_sitter_scala/runtime/grammars/sources/scala \
		6cdh:tree-sitter-scheme:c0741320:6cdh_tree_sitter_scheme/runtime/grammars/sources/scheme \
		serenadeai:tree-sitter-scss:c478c686:serenadeai_tree_sitter_scss/runtime/grammars/sources/scss \
		jrmoulton:tree-sitter-slint:0d4dda94:jrmoulton_tree_sitter_slint/runtime/grammars/sources/slint \
		indoorvivants:tree-sitter-smithy:cf8c7eb9:indoorvivants_tree_sitter_smithy/runtime/grammars/sources/smithy \
		Giorbo:tree-sitter-sml:bd4055d5:Giorbo_tree_sitter_sml/runtime/grammars/sources/sml \
		JoranHonig:tree-sitter-solidity:9004b865:JoranHonig_tree_sitter_solidity/runtime/grammars/sources/solidity \
		DerekStride:tree-sitter-sql:3a3f92b2:DerekStride_tree_sitter_sql/runtime/grammars/sources/sql \
		metio:tree-sitter-ssh-client-config:e45c6d5c:metio_tree_sitter_ssh_client_config/runtime/grammars/sources/sshclientconfig \
		Himujjal:tree-sitter-svelte:349a5984:Himujjal_tree_sitter_svelte/runtime/grammars/sources/svelte \
		FuelLabs:tree-sitter-sway:e491a005:FuelLabs_tree_sitter_sway/runtime/grammars/sources/sway \
		alex-pinkus:tree-sitter-swift:77c6312c:alex_pinkus_tree_sitter_swift/runtime/grammars/sources/swift \
		Flakebi:tree-sitter-tablegen:568dd8a9:Flakebi_tree_sitter_tablegen/runtime/grammars/sources/tablegen \
		alexanderbrevig:tree-sitter-task:f2cb435c:alexanderbrevig_tree_sitter_task/runtime/grammars/sources/task \
		ikatyang:tree-sitter-toml:7cff70bb:ikatyang_tree_sitter_toml/runtime/grammars/sources/toml \
		the-mikedavis:tree-sitter-tsq:48b5e9f8:the_mikedavis_tree_sitter_tsq/runtime/grammars/sources/tsq \
		gbprod:tree-sitter-twig:807b293f:gbprod_tree_sitter_twig/runtime/grammars/sources/twig \
		tree-sitter:tree-sitter-typescript:6aac031a:tree_sitter_tree_sitter_typescript/runtime/grammars/sources/typescript \
		Philipp-M:tree-sitter-ungrammar:0113de88:Philipp_M_tree_sitter_ungrammar/runtime/grammars/sources/ungrammar \
		Jummit:tree-sitter-uxntal:9297e95e:Jummit_tree_sitter_uxntal/runtime/grammars/sources/uxntal \
		vlang:vls:66cf9d30:vlang_vls/runtime/grammars/sources/v \
		vala-lang:tree-sitter-vala:c9eea93b:vala_lang_tree_sitter_vala/runtime/grammars/sources/vala \
		andreytkachenko:tree-sitter-verilog:514d8d70:andreytkachenko_tree_sitter_verilog/runtime/grammars/sources/verilog \
		teburd:tree-sitter-vhdl:c57313ad:teburd_tree_sitter_vhdl/runtime/grammars/sources/vhdl \
		charmbracelet:tree-sitter-vhs:c6d81f34:charmbracelet_tree_sitter_vhs/runtime/grammars/sources/vhs \
		ikatyang:tree-sitter-vue:91fe2754:ikatyang_tree_sitter_vue/runtime/grammars/sources/vue \
		wasm-lsp:tree-sitter-wasm:2ca28a9f:wasm_lsp_tree_sitter_wasm/runtime/grammars/sources/wast \
		szebniok:tree-sitter-wgsl:272e89ef:szebniok_tree_sitter_wgsl/runtime/grammars/sources/wgsl \
		hh9527:tree-sitter-wit:c917790a:hh9527_tree_sitter_wit/runtime/grammars/sources/wit \
		synaptiko:tree-sitter-xit:7d790245:synaptiko_tree_sitter_xit/runtime/grammars/sources/xit \
		RenjiSann:tree-sitter-xml:48a7c2b6:RenjiSann_tree_sitter_xml/runtime/grammars/sources/xml \
		ikatyang:tree-sitter-yaml:0e36bed1:ikatyang_tree_sitter_yaml/runtime/grammars/sources/yaml \
		Philipp-M:tree-sitter-yuck:e3d91a3c:Philipp_M_tree_sitter_yuck/runtime/grammars/sources/yuck \
		maxxnino:tree-sitter-zig:8d3224c3:maxxnino_tree_sitter_zig/runtime/grammars/sources/zig

TREE_SITTER_HARE_REV=	bc26a6a949f2e0d98b7bfc437d459b250900a165
TREE_SITTER_JSHIGH_REV=	4a95461c4761c624f2263725aca79eeaefd36cad
TREE_SITTER_TSHIGH_REV=	6aac031ad88dd6317f02ac0bb27d099a553a7d8c
CARGO_CARGOTOML=	${WRKSRC}/helix-term/Cargo.toml
CARGO_INSTALL_PATH=	./helix-term

post-extract:
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a typescript tsx
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a ocaml ocaml-interface
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a markdown markdown_inline
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a wast wat
	${MV} ${WRKDIR}/tree-sitter-hare-${TREE_SITTER_HARE_REV} ${WRKSRC}/runtime/grammars/sources/hare
	${CP} -R ${DISTDIR}/${TREE_SITTER_TSHIGH_REV}-ts-highlights.scm ${WRKSRC}/runtime/grammars/sources/qmljs/queries/highlights-typescript.scm
	${CP} -R ${DISTDIR}/${TREE_SITTER_JSHIGH_REV}-js-highlights.scm ${WRKSRC}/runtime/grammars/sources/qmljs/queries/highlights-javascript.scm

post-patch:
	${GREP} -F -Rl '%%DATADIR%%' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},'

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/runtime/grammars
.for DIR in queries themes
	cd ${WRKSRC}/runtime && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${DATADIR}/runtime
.endfor
	${INSTALL_DATA} ${WRKSRC}/runtime/tutor ${STAGEDIR}${DATADIR}/runtime/tutor
	${FIND} ${WRKSRC}/runtime/grammars -maxdepth 1 -type f -name '*.so' \
		-exec ${INSTALL_LIB} {} ${STAGEDIR}${DATADIR}/runtime/grammars \;

.include <bsd.port.mk>
