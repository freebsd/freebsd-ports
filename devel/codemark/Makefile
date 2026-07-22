PORTNAME=	codemark
DISTVERSION=	0.7.23
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Semantic code bookmarking system for humans and agents
WWW=		https://github.com/DanielCardonaRojas/codemark

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	DanielCardonaRojas

CARGO_INSTALL_PATH=	crates/codemark-cli crates/codemark-tui

PLIST_FILES=	bin/codemark \
		bin/codemark-tui

.include <bsd.port.mk>
