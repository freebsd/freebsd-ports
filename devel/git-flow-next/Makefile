PORTNAME=	git-flow-next
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	Modern reimplementation of git-flow branching model written in Go
WWW=		https://git-flow.sh

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/gittower/git-flow-next

PLIST_FILES=	bin/git-flow

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/git-flow-next \
		${STAGEDIR}${PREFIX}/bin/git-flow

.include <bsd.port.mk>
