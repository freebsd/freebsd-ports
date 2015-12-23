# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	libgamepad
PORTVERSION=	0.1.2
CATEGORIES=	devel games
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Generic gamepad API

LICENSE=	BSD2CLAUSE

USES=		tar:xz

pre-build:
	(cd ${WRKSRC} && make depend)

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
