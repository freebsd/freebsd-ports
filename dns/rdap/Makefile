PORTNAME=	rdap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	13
CATEGORIES=	dns

MAINTAINER=	pi@FreeBSD.org
COMMENT=	CLI for the Registration Data Access Protocol, RDAP
WWW=		https://www.openrdap.org/

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	openrdap
GH_TAGNAME=	e2ea151
GH_TUPLE=	\
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		jarcoal:httpmock:v1.0.4:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir

GO_TARGET=	cmd/rdap/main.go:rdap
PLIST_FILES=	bin/rdap

.include <bsd.port.mk>
