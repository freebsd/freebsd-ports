PORTNAME=	dwarf2json
DISTVERSION=	g20220807
PORTREVISION=	25
CATEGORIES=	devel

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Convert ELF/DWARF symbol and type information into JSON
WWW=		https://github.com/volatilityfoundation/dwarf2json

LICENSE=	VSL
LICENSE_NAME=	Volatility Software License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	volatilityfoundation
GH_TAGNAME=	c306d11
GH_TUPLE=	spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

USES=		go:modules
PLIST_FILES=	bin/dwarf2json

.include <bsd.port.mk>
