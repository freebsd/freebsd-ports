PORTNAME=	git-town
DISTVERSIONPREFIX=	v
DISTVERSION=	7.7.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git extension for generic, high-level git workflow support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

GO_MODULE=	github.com/git-town/git-town/v7

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
