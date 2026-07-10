PORTNAME=	zk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.5
CATEGORIES=	deskutils

MAINTAINER=	patmaddox@FreeBSD.org
COMMENT=	Plain text note-taking assistant
WWW=		https://zk-org.github.io/zk/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	zk-org

GO_MOD_DIST=	github
GO_MODULE=	github.com/zk-org/zk

GO_BUILDFLAGS+=	-tags "fts5" -ldflags "-X=main.Version=${DISTVERSION}"
GO_TESTFLAGS+=	-tags "fts5"

PLIST_FILES=	bin/zk

.include <bsd.port.mk>
