# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	xmms-fxt
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}oolbox/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Surround/Echo effect plugin for XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gtk12

PLIST_FILES=	lib/xmms/Effect/libfxt.la \
		lib/xmms/Effect/libfxt.so

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/configure ${WRKSRC}/ltconfig

.include <bsd.port.mk>
