PORTNAME=	arttime
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bring curated text/ascii art to artless terminals
WWW=		https://github.com/reportaman/arttime

LICENSE=	GPLv3

BUILD_DEPENDS=	zsh:shells/zsh
RUN_DEPENDS=	zsh:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	reportaman

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${WRKSRC}/install.sh --prefix ${PREFIX}

.include <bsd.port.mk>
