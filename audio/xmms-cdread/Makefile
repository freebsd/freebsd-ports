# Created by: Sergey V. Belov <argail@csite.ru>
# $FreeBSD$

PORTNAME=	xmms-cdread
PORTVERSION=	0.14a
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XMMS input plugin for read AudioCD via IDE bus

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gtk12
NO_STAGE=	yes
USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/xmms/Input/libcdread.so lib/xmms/Input/libcdread.la

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
