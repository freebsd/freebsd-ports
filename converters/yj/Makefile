PORTNAME=	yj
PORTVERSION=	5.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	27
CATEGORIES=	converters
DIST_SUBDIR=	yj

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert between YAML, TOML, JSON, and HCL
WWW=		https://github.com/sclevine/yj

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sclevine
GH_TUPLE=	BurntSushi:toml:v1.1.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		go-yaml:yaml:496545a:go_yaml_yaml/vendor/gopkg.in/yaml.v3

CONFLICTS_INSTALL=	yj-bruceadams

PLIST_FILES=	bin/yj

.include <bsd.port.mk>
