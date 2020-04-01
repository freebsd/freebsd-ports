# $FreeBSD$

PORTNAME=	yj
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	converters
DIST_SUBDIR=	yj

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Convert between YAML, TOML, JSON, and HCL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	sclevine

PLIST_FILES=	bin/yj

GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl

.include <bsd.port.mk>
