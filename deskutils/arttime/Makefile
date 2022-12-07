PORTNAME=	arttime
PORTVERSION=	1.9.8
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bring curated text/ascii art to artless terminals
WWW=		https://github.com/poetaman/arttime

LICENSE=	GPLv3

BUILD_DEPENDS=	zsh>=5.8:shells/zsh
RUN_DEPENDS=	notify-send:devel/libnotify \
		ogg123:audio/vorbis-tools \
		zsh>=5.8:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	poetaman

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${WRKSRC}/install.sh --prefix ${PREFIX}

.include <bsd.port.mk>
