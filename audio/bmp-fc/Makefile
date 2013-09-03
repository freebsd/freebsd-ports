# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bmp-fc
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Future Composer input plug-in for beep-media-player

LICENSE=	GPLv2

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/bmp/Input/libfc.so lib/bmp/Input/libfc.la

post-patch:
	@${REINPLACE_CMD} -e 's|\(objformat=\).*|\1elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
