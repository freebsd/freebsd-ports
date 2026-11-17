PORTNAME=	woodpecker-plugin-git
DISTVERSION=	2.12.1
CATEGORIES=	devel

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Git clone plugin for the Woodpecker CI local backend
WWW=		https://github.com/woodpecker-ci/plugin-git

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:1.27+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	woodpecker-ci
GH_PROJECT=	plugin-git
GO_MOD_DIST=	github
GO_MODULE=	github.com/woodpecker-ci/plugin-git

GO_LDFLAGS=	-X main.version=${DISTVERSION}
GO_TARGET=	.:${PREFIX}/bin/plugin-git

PLIST_FILES=	bin/plugin-git

.include <bsd.port.mk>
