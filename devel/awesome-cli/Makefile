PORTNAME=	awesome-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line tool to explore Awesome lists
WWW=		https://project-awesome.org/umutphp/awesome-cli \
		https://github.com/umutphp/awesome-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	umutphp

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/awesome-cli

.include <bsd.port.mk>
