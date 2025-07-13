PORTNAME=	git-extras
DISTVERSION=	7.4.0
CATEGORIES=	devel

MAINTAINER=	igoro@FreeBSD.org
COMMENT=	Sub-commands for repo summary, repl, changelog population, and more
WWW=		https://github.com/tj/git-extras/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		git:devel/git

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tj

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man/man1

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
