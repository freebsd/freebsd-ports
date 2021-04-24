PORTNAME=	nfpm
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	archivers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple deb, rpm and apk packager written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	goreleaser
GH_TUPLE=	\
		AlekSi:pointer:v1.1.0:aleksi_pointer/vendor/github.com/AlekSi/pointer \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:bf0c5240ed99:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		ProtonMail:go-mime:9b5a4261663a:protonmail_go_mime/vendor/github.com/ProtonMail/go-mime \
		ProtonMail:gopenpgp:v2.1.7:protonmail_gopenpgp_v2/vendor/github.com/ProtonMail/gopenpgp/v2 \
		blakesmith:ar:809d4375e1fb:blakesmith_ar/vendor/github.com/blakesmith/ar \
		cavaliercoder:go-cpio:925f9528c45e:cavaliercoder_go_cpio/vendor/github.com/cavaliercoder/go-cpio \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.1.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.3.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:afb366fc7cd1:golang_net/vendor/golang.org/x/net \
		golang:sys:f1c623a9e750:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:rpmpack:e20c988a6f5a:google_rpmpack/vendor/github.com/google/rpmpack \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		goreleaser:chglog:v0.1.2:goreleaser_chglog/vendor/github.com/goreleaser/chglog \
		goreleaser:fileglob:v1.2.0:goreleaser_fileglob/vendor/github.com/goreleaser/fileglob \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.1.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mitchellh:copystructure:v1.1.2:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		op:go-logging:970db520ece7:op_go_logging/vendor/github.com/op/go-logging \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sassoftware:go-rpmutils:a8f1baeba37b:sassoftware_go_rpmutils/vendor/github.com/sassoftware/go-rpmutils \
		sergi:go-diff:v1.2.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		ulikunitz:xz:v0.5.9:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
