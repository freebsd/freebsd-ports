PORTNAME=	helix
DISTVERSION=	25.01.1
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	https://git.sr.ht/~ecs/tree-sitter-hare/archive/:treesitterhare \
		https://git.sr.ht/~jummit/tree-sitter-wren/archive/:treesitterwren \
		https://git.sr.ht/~sfr/tree-sitter-gemini/archive/:treesittergemini \
		https://raw.githubusercontent.com/tree-sitter/tree-sitter-javascript/${TREE_SITTER_JSHIGH_REV}/queries/highlights.scm?file=/:jshigh \
		https://raw.githubusercontent.com/tree-sitter/tree-sitter-typescript/${TREE_SITTER_TSHIGH_REV}/queries/highlights.scm?file=/:tshigh
DISTFILES=	${TREE_SITTER_HARE_REV}.tar.gz:treesitterhare \
		${TREE_SITTER_WREN_REV}.tar.gz:treesitterwren \
		${TREE_SITTER_GEMINI_REV}.tar.gz:treesittergemini \
		${TREE_SITTER_JSHIGH_REV}-js-highlights.scm:jshigh \
		${TREE_SITTER_TSHIGH_REV}-ts-highlights.scm:tshigh
EXTRACT_ONLY=	${DISTFILES:N*\:*high:C/:[^:]+$//}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Post-modern modal text editor
WWW=		https://helix-editor.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	helix-editor
GH_TUPLE=	\
		briot:tree-sitter-ada:ba0894ef:briot_tree_sitter_ada/runtime/grammars/sources/ada \
		adl-lang:tree-sitter-adl:2787d04b:adl_lang_tree_sitter_adl/runtime/grammars/sources/adl \
		tree-sitter:tree-sitter-agda:c21c3a0f:tree_sitter_tree_sitter_agda/runtime/grammars/sources/agda \
		amber-lang:tree-sitter-amber:c6df3ec2:amber_lang_tree_sitter_amber/runtime/grammars/sources/amber \
		virchau13:tree-sitter-astro:947e9308:virchau13_tree_sitter_astro/runtime/grammars/sources/astro \
		Beaglefoot:tree-sitter-awk:a799bc5d:Beaglefoot_tree_sitter_awk/runtime/grammars/sources/awk \
		tree-sitter:tree-sitter-bash:f8fb3274:tree_sitter_tree_sitter_bash/runtime/grammars/sources/bash \
		vito:tree-sitter-bass:501133e2:vito_tree_sitter_bass/runtime/grammars/sources/bass \
		polarmutex:tree-sitter-beancount:f3741a3a:polarmutex_tree_sitter_beancount/runtime/grammars/sources/beancount \
		latex-lsp:tree-sitter-bibtex:ccfd77db:latex_lsp_tree_sitter_bibtex/runtime/grammars/sources/bibtex \
		tree-sitter-grammars:tree-sitter-bicep:0092c7d1:tree_sitter_grammars_tree_sitter_bicep/runtime/grammars/sources/bicep \
		tree-sitter-grammars:tree-sitter-bitbake:10bacac9:tree_sitter_grammars_tree_sitter_bitbake/runtime/grammars/sources/bitbake \
		EmranMR:tree-sitter-blade:4c66efe1:EmranMR_tree_sitter_blade/runtime/grammars/sources/blade \
		tree-sitter:tree-sitter-c:7175a6dd:tree_sitter_tree_sitter_c/runtime/grammars/sources/c \
		starkware-libs:tree-sitter-cairo:e3a02122:starkware_libs_tree_sitter_cairo/runtime/grammars/sources/cairo \
		amaanq:tree-sitter-capnp:fc6e2add:amaanq_tree_sitter_capnp/runtime/grammars/sources/capnp \
		bufbuild:tree-sitter-cel:9f2b65da:bufbuild_tree_sitter_cel/runtime/grammars/sources/cel \
		Decurity:tree-sitter-circom:02150524:Decurity_tree_sitter_circom/runtime/grammars/sources/circom \
		sogaiu:tree-sitter-clojure:e57c569a:sogaiu_tree_sitter_clojure/runtime/grammars/sources/clojure \
		uyha:tree-sitter-cmake:6e51463e:uyha_tree_sitter_cmake/runtime/grammars/sources/cmake \
		stsewd:tree-sitter-comment:aefcc281:stsewd_tree_sitter_comment/runtime/grammars/sources/comment \
		fvacek:tree-sitter-cpon:0d01fcda:fvacek_tree_sitter_cpon/runtime/grammars/sources/cpon \
		tree-sitter:tree-sitter-cpp:670404d7:tree_sitter_tree_sitter_cpp/runtime/grammars/sources/cpp \
		tree-sitter:tree-sitter-c-sharp:5b60f995:tree_sitter_tree_sitter_c_sharp/runtime/grammars/sources/c-sharp \
		tree-sitter:tree-sitter-css:769203d0:tree_sitter_tree_sitter_css/runtime/grammars/sources/css \
		eonpatapon:tree-sitter-cue:61843e3b:eonpatapon_tree_sitter_cue/runtime/grammars/sources/cue \
		elliotfontaine:tree-sitter-cylc:30dd40d9:elliotfontaine_tree_sitter_cylc/runtime/grammars/sources/cylc \
		gdamore:tree-sitter-d:5566f8ce:gdamore_tree_sitter_d/runtime/grammars/sources/d \
		UserNobody14:tree-sitter-dart:e398400a:UserNobody14_tree_sitter_dart/runtime/grammars/sources/dart \
		dynamotn:tree-sitter-dbml:2e2fa564:dynamotn_tree_sitter_dbml/runtime/grammars/sources/dbml \
		joelspadin:tree-sitter-devicetree:877adbfa:joelspadin_tree_sitter_devicetree/runtime/grammars/sources/devicetree \
		jbellerb:tree-sitter-dhall:affb6ee3:jbellerb_tree_sitter_dhall/runtime/grammars/sources/dhall \
		the-mikedavis:tree-sitter-diff:fd74c78f:the_mikedavis_tree_sitter_diff/runtime/grammars/sources/diff \
		camdencheek:tree-sitter-dockerfile:087daa20:camdencheek_tree_sitter_dockerfile/runtime/grammars/sources/dockerfile \
		rydesun:tree-sitter-dot:91723074:rydesun_tree_sitter_dot/runtime/grammars/sources/dot \
		KMikeeU:tree-sitter-dtd:6116becb:KMikeeU_tree_sitter_dtd/runtime/grammars/sources/dtd \
		glehmann:tree-sitter-earthfile:dbfb970a:glehmann_tree_sitter_earthfile/runtime/grammars/sources/earthfile \
		the-mikedavis:tree-sitter-edoc:74774af7:the_mikedavis_tree_sitter_edoc/runtime/grammars/sources/edoc \
		connorlay:tree-sitter-eex:f742f2fe:connorlay_tree_sitter_eex/runtime/grammars/sources/eex \
		Wilfred:tree-sitter-elisp:e5524fdc:Wilfred_tree_sitter_elisp/runtime/grammars/sources/elisp \
		elixir-lang:tree-sitter-elixir:b20eaa75:elixir_lang_tree_sitter_elixir/runtime/grammars/sources/elixir \
		elm-tooling:tree-sitter-elm:df4cb639:elm_tooling_tree_sitter_elm/runtime/grammars/sources/elm \
		ckafi:tree-sitter-elvish:e50787ca:ckafi_tree_sitter_elvish/runtime/grammars/sources/elvish \
		tree-sitter:tree-sitter-embedded-template:d21df11b:tree_sitter_tree_sitter_embedded_template/runtime/grammars/sources/embedded-template \
		the-mikedavis:tree-sitter-erlang:9d4b36a7:the_mikedavis_tree_sitter_erlang/runtime/grammars/sources/erlang \
		greym0uth:tree-sitter-esdl:df83acc8:greym0uth_tree_sitter_esdl/runtime/grammars/sources/esdl \
		google:tree-sitter-fidl:bdbb635a:google_tree_sitter_fidl/runtime/grammars/sources/fidl \
		ram02z:tree-sitter-fish:84436cf2:ram02z_tree_sitter_fish/runtime/grammars/sources/fish \
		alexanderbrevig:tree-sitter-forth:90189238:alexanderbrevig_tree_sitter_forth/runtime/grammars/sources/forth \
		stadelmanma:tree-sitter-fortran:f0f2f100:stadelmanma_tree_sitter_fortran/runtime/grammars/sources/fortran \
		ionide:tree-sitter-fsharp:996ea998:ionide_tree_sitter_fsharp/runtime/grammars/sources/fsharp \
		sirius94:tree-sitter-gas:60f44364:sirius94_tree_sitter_gas/runtime/grammars/sources/gas \
		PrestonKnopp:tree-sitter-gdscript:1f1e782f:PrestonKnopp_tree_sitter_gdscript/runtime/grammars/sources/gdscript \
		SamyAB:tree-sitter-gherkin:43873ee8:SamyAB_tree_sitter_gherkin/runtime/grammars/sources/gherkin \
		mtoohey31:tree-sitter-gitattributes:3dd50808:mtoohey31_tree_sitter_gitattributes/runtime/grammars/sources/gitattributes \
		the-mikedavis:tree-sitter-git-commit:6f193a66:the_mikedavis_tree_sitter_git_commit/runtime/grammars/sources/git-commit \
		the-mikedavis:tree-sitter-git-config:9c2a1b78:the_mikedavis_tree_sitter_git_config/runtime/grammars/sources/git-config \
		shunsambongi:tree-sitter-gitignore:f4685bf1:shunsambongi_tree_sitter_gitignore/runtime/grammars/sources/gitignore \
		the-mikedavis:tree-sitter-git-rebase:d8a4207e:the_mikedavis_tree_sitter_git_rebase/runtime/grammars/sources/git-rebase \
		gleam-lang:tree-sitter-gleam:426e6708:gleam_lang_tree_sitter_gleam/runtime/grammars/sources/gleam \
		ember-tooling:tree-sitter-glimmer:5dc6d104:ember_tooling_tree_sitter_glimmer/runtime/grammars/sources/glimmer \
		theHamsta:tree-sitter-glsl:88408ffc:theHamsta_tree_sitter_glsl/runtime/grammars/sources/glsl \
		willcassella:tree-sitter-gn:e18d6e36:willcassella_tree_sitter_gn/runtime/grammars/sources/gn \
		tree-sitter:tree-sitter-go:64457ea6:tree_sitter_tree_sitter_go/runtime/grammars/sources/go \
		PrestonKnopp:tree-sitter-godot-resource:2ffb90de:PrestonKnopp_tree_sitter_godot_resource/runtime/grammars/sources/godot-resource \
		camdencheek:tree-sitter-go-mod:e8f51f8e:camdencheek_tree_sitter_go_mod/runtime/grammars/sources/gomod \
		dannylongeuay:tree-sitter-go-template:395a33e0:dannylongeuay_tree_sitter_go_template/runtime/grammars/sources/gotmpl \
		omertuc:tree-sitter-go-work:6dd9dd79:omertuc_tree_sitter_go_work/runtime/grammars/sources/gowork \
		brownts:tree-sitter-gpr:cea857d3:brownts_tree_sitter_gpr/runtime/grammars/sources/gpr \
		bkegley:tree-sitter-graphql:5e66e961:bkegley_tree_sitter_graphql/runtime/grammars/sources/graphql \
		MaeBrooks:tree-sitter-gren:76554f4f:MaeBrooks_tree_sitter_gren/runtime/grammars/sources/gren \
		murtaza64:tree-sitter-groovy:235009aa:murtaza64_tree_sitter_groovy/runtime/grammars/sources/groovy \
		tree-sitter:tree-sitter-haskell:d7ac98f4:tree_sitter_tree_sitter_haskell/runtime/grammars/sources/haskell \
		MercuryTechnologies:tree-sitter-haskell-persistent:58a6ccfd:MercuryTechnologies_tree_sitter_haskell_persistent/runtime/grammars/sources/haskell-persistent \
		tree-sitter-grammars:tree-sitter-hcl:9e3ec984:tree_sitter_grammars_tree_sitter_hcl/runtime/grammars/sources/hcl \
		phoenixframework:tree-sitter-heex:f6b83f30:phoenixframework_tree_sitter_heex/runtime/grammars/sources/heex \
		antosha417:tree-sitter-hocon:c390f105:antosha417_tree_sitter_hocon/runtime/grammars/sources/hocon \
		urbit-pilled:tree-sitter-hoon:1d5df35a:urbit_pilled_tree_sitter_hoon/runtime/grammars/sources/hoon \
		ath3:tree-sitter-hosts:301b9379:ath3_tree_sitter_hosts/runtime/grammars/sources/hosts \
		tree-sitter:tree-sitter-html:29f53d8f:tree_sitter_tree_sitter_html/runtime/grammars/sources/html \
		pfeiferj:tree-sitter-hurl:cd1a0ada:pfeiferj_tree_sitter_hurl/runtime/grammars/sources/hurl \
		tree-sitter-grammars:tree-sitter-hyprlang:27af9b74:tree_sitter_grammars_tree_sitter_hyprlang/runtime/grammars/sources/hyprlang \
		elixir-lang:tree-sitter-iex:39f20bb5:elixir_lang_tree_sitter_iex/runtime/grammars/sources/iex \
		justinmk:tree-sitter-ini:4d247fb8:justinmk_tree_sitter_ini/runtime/grammars/sources/ini \
		inko-lang:tree-sitter-inko:7860637c:inko_lang_tree_sitter_inko/runtime/grammars/sources/inko \
		sogaiu:tree-sitter-janet-simple:51271e26:sogaiu_tree_sitter_janet_simple/runtime/grammars/sources/janet-simple \
		tree-sitter:tree-sitter-java:09d650de:tree_sitter_tree_sitter_java/runtime/grammars/sources/java \
		tree-sitter:tree-sitter-javascript:f772967f:tree_sitter_tree_sitter_javascript/runtime/grammars/sources/javascript \
		varpeti:tree-sitter-jinja2:a533cd3c:varpeti_tree_sitter_jinja2/runtime/grammars/sources/jinja2 \
		kareigu:tree-sitter-jjdescription:d09205b5:kareigu_tree_sitter_jjdescription/runtime/grammars/sources/jjdescription \
		flurie:tree-sitter-jq:13990f53:flurie_tree_sitter_jq/runtime/grammars/sources/jq \
		tree-sitter:tree-sitter-jsdoc:189a6a48:tree_sitter_tree_sitter_jsdoc/runtime/grammars/sources/jsdoc \
		tree-sitter:tree-sitter-json:73076754:tree_sitter_tree_sitter_json/runtime/grammars/sources/json \
		Joakker:tree-sitter-json5:c23f7a9b:Joakker_tree_sitter_json5/runtime/grammars/sources/json5 \
		sourcegraph:tree-sitter-jsonnet:0475a501:sourcegraph_tree_sitter_jsonnet/runtime/grammars/sources/jsonnet \
		tree-sitter:tree-sitter-julia:8fb38abf:tree_sitter_tree_sitter_julia/runtime/grammars/sources/julia \
		poliorcetics:tree-sitter-just:180bb15d:poliorcetics_tree_sitter_just/runtime/grammars/sources/just \
		amaanq:tree-sitter-kdl:3ca569b9:amaanq_tree_sitter_kdl/runtime/grammars/sources/kdl \
		mtoohey31:tree-sitter-koka:96d070c3:mtoohey31_tree_sitter_koka/runtime/grammars/sources/koka \
		fwcd:tree-sitter-kotlin:a4f71eb9:fwcd_tree_sitter_kotlin/runtime/grammars/sources/kotlin \
		koto-lang:tree-sitter-koto:b420f792:koto_lang_tree_sitter_koto/runtime/grammars/sources/koto \
		latex-lsp:tree-sitter-latex:8c75e93c:latex_lsp_tree_sitter_latex/runtime/grammars/sources/latex \
		mtoohey31:tree-sitter-ld:0e9695ae:mtoohey31_tree_sitter_ld/runtime/grammars/sources/ld \
		kepet19:tree-sitter-ldif:0a917207:kepet19_tree_sitter_ldif/runtime/grammars/sources/ldif \
		Julian:tree-sitter-lean:d9842610:Julian_tree_sitter_lean/runtime/grammars/sources/lean \
		cbarrete:tree-sitter-ledger:1f864fb2:cbarrete_tree_sitter_ledger/runtime/grammars/sources/ledger \
		benwilliamgraham:tree-sitter-llvm:c14cb839:benwilliamgraham_tree_sitter_llvm/runtime/grammars/sources/llvm \
		Flakebi:tree-sitter-llvm-mir:d166ff8c:Flakebi_tree_sitter_llvm_mir/runtime/grammars/sources/llvm-mir \
		Tudyx:tree-sitter-log:62cfe307:Tudyx_tree_sitter_log/runtime/grammars/sources/log \
		tree-sitter-grammars:tree-sitter-lua:88e44647:tree_sitter_grammars_tree_sitter_lua/runtime/grammars/sources/lua \
		alemuller:tree-sitter-make:a4b91874:alemuller_tree_sitter_make/runtime/grammars/sources/make \
		markdoc-extra:tree-sitter-markdoc:5ffe71b2:markdoc_extra_tree_sitter_markdoc/runtime/grammars/sources/markdoc \
		tree-sitter-grammars:tree-sitter-markdown:62516e8c:tree_sitter_grammars_tree_sitter_markdown/runtime/grammars/sources/markdown \
		acristoffers:tree-sitter-matlab:b0a0198b:acristoffers_tree_sitter_matlab/runtime/grammars/sources/matlab \
		monaqa:tree-sitter-mermaid:d787c662:monaqa_tree_sitter_mermaid/runtime/grammars/sources/mermaid \
		staysail:tree-sitter-meson:32a83e8f:staysail_tree_sitter_meson/runtime/grammars/sources/meson \
		lsh:tree-sitter-mojo:3d7c53b8:lsh_tree_sitter_mojo/runtime/grammars/sources/mojo \
		tzakian:tree-sitter-move:8bc0d169:tzakian_tree_sitter_move/runtime/grammars/sources/move \
		naclsn:tree-sitter-nasm:570f3d7b:naclsn_tree_sitter_nasm/runtime/grammars/sources/nasm \
		nickel-lang:tree-sitter-nickel:88d836a2:nickel_lang_tree_sitter_nickel/runtime/grammars/sources/nickel \
		alaviss:tree-sitter-nim:c5f0ce3b:alaviss_tree_sitter_nim/runtime/grammars/sources/nim \
		nix-community:tree-sitter-nix:1b69cf1f:nix_community_tree_sitter_nix/runtime/grammars/sources/nix \
		nushell:tree-sitter-nu:358c4f50:nushell_tree_sitter_nu/runtime/grammars/sources/nu \
		tree-sitter:tree-sitter-ocaml:9965d208:tree_sitter_tree_sitter_ocaml/runtime/grammars/sources/ocaml \
		tree-sitter-grammars:tree-sitter-odin:b5f668ef:tree_sitter_grammars_tree_sitter_odin/runtime/grammars/sources/odin \
		novusnota:tree-sitter-ohm:80f14f0e:novusnota_tree_sitter_ohm/runtime/grammars/sources/ohm \
		lefp:tree-sitter-opencl:8e1d24a5:lefp_tree_sitter_opencl/runtime/grammars/sources/opencl \
		bollian:tree-sitter-openscad:5c3ce93d:bollian_tree_sitter_openscad/runtime/grammars/sources/openscad \
		milisims:tree-sitter-org:698bb1a3:milisims_tree_sitter_org/runtime/grammars/sources/org \
		Isopod:tree-sitter-pascal:2fd40f47:Isopod_tree_sitter_pascal/runtime/grammars/sources/pascal \
		ath3:tree-sitter-passwd:20239395:ath3_tree_sitter_passwd/runtime/grammars/sources/passwd \
		mtoohey31:tree-sitter-pem:be67a433:mtoohey31_tree_sitter_pem/runtime/grammars/sources/pem \
		tree-sitter-perl:tree-sitter-perl:72a08a49:tree_sitter_perl_tree_sitter_perl/runtime/grammars/sources/perl \
		pest-parser:tree-sitter-pest:a8a98a82:pest_parser_tree_sitter_pest/runtime/grammars/sources/pest \
		tree-sitter:tree-sitter-php:f860e598:tree_sitter_tree_sitter_php/runtime/grammars/sources/php \
		tree-sitter:tree-sitter-php:cf1f4a0f:tree_sitter_tree_sitter_php_only/runtime/grammars/sources/php-only \
		apple:tree-sitter-pkl:c03f04a3:apple_tree_sitter_pkl/runtime/grammars/sources/pkl \
		erasin:tree-sitter-po:417cee9a:erasin_tree_sitter_po/runtime/grammars/sources/po \
		tree-sitter-perl:tree-sitter-pod:0bf83879:tree_sitter_perl_tree_sitter_pod/runtime/grammars/sources/pod \
		mfelsche:tree-sitter-ponylang:ef66b151:mfelsche_tree_sitter_ponylang/runtime/grammars/sources/ponylang \
		airbus-cert:tree-sitter-powershell:c9316be0:airbus_cert_tree_sitter_powershell/runtime/grammars/sources/powershell \
		victorhqc:tree-sitter-prisma:eca2596a:victorhqc_tree_sitter_prisma/runtime/grammars/sources/prisma \
		sdoerner:tree-sitter-proto:778ab6ed:sdoerner_tree_sitter_proto/runtime/grammars/sources/proto \
		PRQL:tree-sitter-prql:09e158cd:PRQL_tree_sitter_prql/runtime/grammars/sources/prql \
		postsolar:tree-sitter-purescript:5ef55926:postsolar_tree_sitter_purescript/runtime/grammars/sources/purescript \
		tree-sitter:tree-sitter-python:4bfdd903:tree_sitter_tree_sitter_python/runtime/grammars/sources/python \
		tree-sitter:tree-sitter-ql:1fd627a4:tree_sitter_tree_sitter_ql/runtime/grammars/sources/ql \
		yuja:tree-sitter-qmljs:0b2b25bc:yuja_tree_sitter_qmljs/runtime/grammars/sources/qmljs \
		tree-sitter-grammars:tree-sitter-query:a6674e27:tree_sitter_grammars_tree_sitter_query/runtime/grammars/sources/query \
		gruhn:tree-sitter-quint:eebbd01e:gruhn_tree_sitter_quint/runtime/grammars/sources/quint \
		r-lib:tree-sitter-r:cc04302e:r_lib_tree_sitter_r/runtime/grammars/sources/r \
		tree-sitter:tree-sitter-regex:e1cfca3c:tree_sitter_tree_sitter_regex/runtime/grammars/sources/regex \
		FallenAngel97:tree-sitter-rego:9ac75e71:FallenAngel97_tree_sitter_rego/runtime/grammars/sources/rego \
		rescript-lang:tree-sitter-rescript:5e2a44a9:rescript_lang_tree_sitter_rescript/runtime/grammars/sources/rescript \
		Hubro:tree-sitter-robot:322e4cc6:Hubro_tree_sitter_robot/runtime/grammars/sources/robot \
		zee-editor:tree-sitter-ron:7762d709:zee_editor_tree_sitter_ron/runtime/grammars/sources/ron \
		stsewd:tree-sitter-rst:25e63288:stsewd_tree_sitter_rst/runtime/grammars/sources/rst \
		tree-sitter:tree-sitter-ruby:206c7077:tree_sitter_tree_sitter_ruby/runtime/grammars/sources/ruby \
		tree-sitter:tree-sitter-rust:9c84af00:tree_sitter_tree_sitter_rust/runtime/grammars/sources/rust \
		tree-sitter:tree-sitter-scala:7891815f:tree_sitter_tree_sitter_scala/runtime/grammars/sources/scala \
		6cdh:tree-sitter-scheme:af3af6c9:6cdh_tree_sitter_scheme/runtime/grammars/sources/scheme \
		serenadeai:tree-sitter-scss:c478c686:serenadeai_tree_sitter_scss/runtime/grammars/sources/scss \
		slint-ui:tree-sitter-slint:f11da7e6:slint_ui_tree_sitter_slint/runtime/grammars/sources/slint \
		amaanq:tree-sitter-smali:5ae51e15:amaanq_tree_sitter_smali/runtime/grammars/sources/smali \
		indoorvivants:tree-sitter-smithy:8327eb84:indoorvivants_tree_sitter_smithy/runtime/grammars/sources/smithy \
		Giorbo:tree-sitter-sml:bd4055d5:Giorbo_tree_sitter_sml/runtime/grammars/sources/sml \
		osthomas:tree-sitter-snakemake:e909815a:osthomas_tree_sitter_snakemake/runtime/grammars/sources/snakemake \
		JoranHonig:tree-sitter-solidity:f7f5251a:JoranHonig_tree_sitter_solidity/runtime/grammars/sources/solidity \
		jzelinskie:tree-sitter-spicedb:a4e46456:jzelinskie_tree_sitter_spicedb/runtime/grammars/sources/spicedb \
		DerekStride:tree-sitter-sql:da2d1eff:DerekStride_tree_sitter_sql/runtime/grammars/sources/sql \
		metio:tree-sitter-ssh-client-config:e45c6d5c:metio_tree_sitter_ssh_client_config/runtime/grammars/sources/sshclientconfig \
		sigmaSd:tree-sitter-strace:2b18fdf9:sigmaSd_tree_sitter_strace/runtime/grammars/sources/strace \
		madskjeldgaard:tree-sitter-supercollider:3b35bd0f:madskjeldgaard_tree_sitter_supercollider/runtime/grammars/sources/supercollider \
		Himujjal:tree-sitter-svelte:be7f2e7d:Himujjal_tree_sitter_svelte/runtime/grammars/sources/svelte \
		FuelLabs:tree-sitter-sway:e491a005:FuelLabs_tree_sitter_sway/runtime/grammars/sources/sway \
		alex-pinkus:tree-sitter-swift:57c1c6d6:alex_pinkus_tree_sitter_swift/runtime/grammars/sources/swift \
		Flakebi:tree-sitter-tablegen:3e9c4822:Flakebi_tree_sitter_tablegen/runtime/grammars/sources/tablegen \
		tact-lang:tree-sitter-tact:ec57ab29:tact_lang_tree_sitter_tact/runtime/grammars/sources/tact \
		alexanderbrevig:tree-sitter-task:f2cb435c:alexanderbrevig_tree_sitter_task/runtime/grammars/sources/task \
		tree-sitter-grammars:tree-sitter-tcl:56ad1fa6:tree_sitter_grammars_tree_sitter_tcl/runtime/grammars/sources/tcl \
		euclidianAce:tree-sitter-teal:3db65592:euclidianAce_tree_sitter_teal/runtime/grammars/sources/teal \
		vrischmann:tree-sitter-templ:db662414:vrischmann_tree_sitter_templ/runtime/grammars/sources/templ \
		PorterAtGoogle:tree-sitter-textproto:568471b8:PorterAtGoogle_tree_sitter_textproto/runtime/grammars/sources/textproto \
		tree-sitter-grammars:tree-sitter-thrift:68fd0d80:tree_sitter_grammars_tree_sitter_thrift/runtime/grammars/sources/thrift \
		arnarg:tree-sitter-todotxt:3937c5cd:arnarg_tree_sitter_todotxt/runtime/grammars/sources/todotxt \
		ikatyang:tree-sitter-toml:7cff70bb:ikatyang_tree_sitter_toml/runtime/grammars/sources/toml \
		gbprod:tree-sitter-twig:807b293f:gbprod_tree_sitter_twig/runtime/grammars/sources/twig \
		tree-sitter:tree-sitter-typescript:b1bf4825:tree_sitter_tree_sitter_typescript/runtime/grammars/sources/typescript \
		happenslol:tree-sitter-typespec:0ee05546:happenslol_tree_sitter_typespec/runtime/grammars/sources/typespec \
		uben0:tree-sitter-typst:13863ddc:uben0_tree_sitter_typst/runtime/grammars/sources/typst \
		Philipp-M:tree-sitter-ungrammar:a7e10462:Philipp_M_tree_sitter_ungrammar/runtime/grammars/sources/ungrammar \
		kylegoetz:tree-sitter-unison:3c97db76:kylegoetz_tree_sitter_unison/runtime/grammars/sources/unison \
		Jummit:tree-sitter-uxntal:d6840606:Jummit_tree_sitter_uxntal/runtime/grammars/sources/uxntal \
		vlang:v-analyzer:e14fdf6e:vlang_v_analyzer/runtime/grammars/sources/v \
		vala-lang:tree-sitter-vala:c9eea93b:vala_lang_tree_sitter_vala/runtime/grammars/sources/vala \
		ventojs:tree-sitter-vento:3b32474b:ventojs_tree_sitter_vento/runtime/grammars/sources/vento \
		tree-sitter:tree-sitter-verilog:4457145e:tree_sitter_tree_sitter_verilog/runtime/grammars/sources/verilog \
		teburd:tree-sitter-vhdl:c57313ad:teburd_tree_sitter_vhdl/runtime/grammars/sources/vhdl \
		charmbracelet:tree-sitter-vhs:9534865e:charmbracelet_tree_sitter_vhs/runtime/grammars/sources/vhs \
		ikatyang:tree-sitter-vue:91fe2754:ikatyang_tree_sitter_vue/runtime/grammars/sources/vue \
		wasm-lsp:tree-sitter-wasm:2ca28a9f:wasm_lsp_tree_sitter_wasm/runtime/grammars/sources/wast \
		szebniok:tree-sitter-wgsl:272e89ef:szebniok_tree_sitter_wgsl/runtime/grammars/sources/wgsl \
		hh9527:tree-sitter-wit:c917790a:hh9527_tree_sitter_wit/runtime/grammars/sources/wit \
		synaptiko:tree-sitter-xit:7d790245:synaptiko_tree_sitter_xit/runtime/grammars/sources/xit \
		RenjiSann:tree-sitter-xml:48a7c2b6:RenjiSann_tree_sitter_xml/runtime/grammars/sources/xml \
		Alexis-Lapierre:tree-sitter-xtc:7bc11b73:Alexis_Lapierre_tree_sitter_xtc/runtime/grammars/sources/xtc \
		ikatyang:tree-sitter-yaml:0e36bed1:ikatyang_tree_sitter_yaml/runtime/grammars/sources/yaml \
		Philipp-M:tree-sitter-yuck:e3d91a3c:Philipp_M_tree_sitter_yuck/runtime/grammars/sources/yuck \
		maxxnino:tree-sitter-zig:0d08703e:maxxnino_tree_sitter_zig/runtime/grammars/sources/zig
USE_GITLAB=	nodefault
GL_TUPLE=	\
		https://gitlab.com:gabmus:tree-sitter-blueprint:863cea9f:gabmus_tree_sitter_blueprint/runtime/grammars/sources/blueprint \
		https://gitlab.com:TheZoq2:tree-sitter-lpf:db7372e6:TheZoq2_tree_sitter_lpf/runtime/grammars/sources/lpf \
		https://gitlab.com:joncoole:tree-sitter-nginx:b4b61db4:joncoole_tree_sitter_nginx/runtime/grammars/sources/nginx \
		https://gitlab.com:spade-lang:tree-sitter-spade:78bf09a8:spade_lang_tree_sitter_spade/runtime/grammars/sources/spade \
		https://gitlab.com:xasc:tree-sitter-t32:6da5e3cb:xasc_tree_sitter_t32/runtime/grammars/sources/t32

TREE_SITTER_HARE_REV=	07035a248943575444aa0b893ffe306e1444c0ab
TREE_SITTER_WREN_REV=	6748694be32f11e7ec6b5faeb1b48ca6156d4e06
TREE_SITTER_GEMINI_REV=	3cc5e4bdf572d5df4277fc2e54d6299bd59a54b3
TREE_SITTER_JSHIGH_REV=	936d976a782e75395d9b1c8c7c7bf4ba6fe0d86b
TREE_SITTER_TSHIGH_REV=	0ab9d99867435a7667c5548a6617a6bf73dbd830
CARGO_CARGOTOML=	${WRKSRC}/helix-term/Cargo.toml
CARGO_INSTALL_PATH=	./helix-term

CONFLICTS_INSTALL=	shx

post-extract:
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a typescript tsx
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a ocaml ocaml-interface
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a markdown markdown_inline
	cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a wast wat
	${MV} ${WRKDIR}/tree-sitter-hare-${TREE_SITTER_HARE_REV} ${WRKSRC}/runtime/grammars/sources/hare
	${MV} ${WRKDIR}/tree-sitter-wren-${TREE_SITTER_WREN_REV} ${WRKSRC}/runtime/grammars/sources/wren
	${MV} ${WRKDIR}/tree-sitter-gemini-${TREE_SITTER_GEMINI_REV} ${WRKSRC}/runtime/grammars/sources/gemini
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
