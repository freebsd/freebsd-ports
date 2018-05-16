# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	julius
PKGNAMESUFFIX=	-caesariii
PORTVERSION=	g20180430
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open source re-implementation of Caesar III

LICENSE=	GPLv3

USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	bvschaik
GH_TAGNAME=	cb7ecdf

USE_SDL=	mixer2 sdl2

SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
