# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-ahx
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing AHX tunes

LICENSE=	GPLv2

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libahx.la \
		lib/xmms/Input/libahx.so

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|\(objformat=\).*|\1elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
