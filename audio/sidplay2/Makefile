# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	sidplay2
PORTVERSION=	2.0.9
CATEGORIES=	audio emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sidplay-${PORTVERSION}
DISTNAME=	sidplay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID music player using libsidplay2

LIB_DEPENDS=	sidplay2:${PORTSDIR}/audio/libsidplay2

GNU_CONFIGURE=	yes
USES=		pkgconfig
NO_STAGE=	yes

MAN1=		sidplay2.1
PLIST_FILES=	bin/sidplay2

.include <bsd.port.mk>
