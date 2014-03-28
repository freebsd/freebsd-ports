# Created by: James McNaughton
# $FreeBSD$

PORTNAME=	xmms-nas
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	bitbucket63-it@yahoo.com
COMMENT=	A Network Audio System (NAS) output plugin for XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms \
		libaudio.so:${PORTSDIR}/audio/nas

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Output/libnas.a \
		lib/xmms/Output/libnas.la \
		lib/xmms/Output/libnas.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
