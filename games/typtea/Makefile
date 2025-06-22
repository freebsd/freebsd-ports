PORTNAME=	typtea
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	games

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Minimal terminal-based typing speed test
WWW=		https://github.com/ashish0kumar/typtea

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/ashish0kumar/typtea

GO_BUILDFLAGS+=	-ldflags="-s -w -X github.com/ashish0kumar/typtea/cmd.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/typtea

.include <bsd.port.mk>
