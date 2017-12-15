# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	residualvm
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	yerenkow@gmail.com
COMMENT=	ResidualVM allows you to indulge with classic games like Grim Fandango

BROKEN_armv6=		fails to link: ld: libgrim.a has EABI version 0, but target residualvm has EABI version 5
BROKEN_armv7=		fails to link: ld: libgrim.a has EABI version 0, but target residualvm has EABI version 5

USE_GITHUB=	yes

USE_SDL=	sdl
HAS_CONFIGURE=	yes
USES=		gmake

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|{datarootdir}/man|{prefix}/man|' ${WRKSRC}/configure

.include <bsd.port.mk>
