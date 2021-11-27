PORTNAME=	yj
PORTVERSION=	5.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	converters
DIST_SUBDIR=	yj

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert between YAML, TOML, JSON, and HCL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	sclevine

CONFLICTS_INSTALL=	yj-bruceadams

PLIST_FILES=	bin/yj

GH_TUPLE=	go-yaml:yaml:eeeca48fe776:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		sclevine:go-toml:ed50a274ac56:sclevine_go_toml/vendor/github.com/pelletier/go-toml

.include <bsd.port.mk>
