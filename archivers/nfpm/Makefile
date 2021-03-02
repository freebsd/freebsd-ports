# $FreeBSD$

PORTNAME=	nfpm
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
CATEGORIES=	archivers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple deb, rpm and apk packager written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	goreleaser
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Djarvur:go-err113:v0.1.0:djarvur_go_err113/vendor/github.com/Djarvur/go-err113 \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		blakesmith:ar:809d4375e1fb:blakesmith_ar/vendor/github.com/blakesmith/ar \
		cavaliercoder:go-cpio:925f9528c45e:cavaliercoder_go_cpio/vendor/github.com/cavaliercoder/go-cpio \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.0.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.2.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:crypto:5f87f3452ae9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ac852fbbde11:golang_net/vendor/golang.org/x/net \
		golang:sys:d4d67f95c62d:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:rpmpack:0a97c2c4b688:google_rpmpack/vendor/github.com/google/rpmpack \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		goreleaser:chglog:v0.1.2:goreleaser_chglog/vendor/github.com/goreleaser/chglog \
		goreleaser:fileglob:v1.2.0:goreleaser_fileglob/vendor/github.com/goreleaser/fileglob \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:4977a11b4351:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		op:go-logging:970db520ece7:op_go_logging/vendor/github.com/op/go-logging \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sassoftware:go-rpmutils:a8f1baeba37b:sassoftware_go_rpmutils/vendor/github.com/sassoftware/go-rpmutils \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		ulikunitz:xz:v0.5.9:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
