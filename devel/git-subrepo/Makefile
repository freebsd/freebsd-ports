PORTNAME=	git-subrepo
DISTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Git command for managing subrepositories
WWW=		https://github.com/ingydotnet/git-subrepo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	bash:shells/bash \
		git:devel/git

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ingydotnet

NO_ARCH=	yes
NO_BUILD=	yes

MAKE_ARGS=	INSTALL_MAN1="\$${DESTDIR}\$${PREFIX}/share/man/man1"

.include <bsd.port.mk>
