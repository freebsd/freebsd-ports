PORTNAME=	glab-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal user interface for GitLab and GitHub
WWW=		https://github.com/rcieri/glab-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	gh:devel/gh \
		git:devel/git \
		glab:devel/glab

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rcieri

PLIST_FILES=	bin/glab-tui

.include <bsd.port.mk>
