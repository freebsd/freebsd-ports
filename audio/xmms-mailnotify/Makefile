# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-mailnotify
PORTVERSION=	0.2.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	XMMS plugin, that plays a sound on incoming mail and opens the MUA

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/General/libmailnotify.so \
		lib/xmms/General/alert.wav

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib,${LOCALBASE}/lib," ${WRKSRC}/mailnotify.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/General/
	@${INSTALL_DATA} ${WRKSRC}/libmailnotify.so ${STAGEDIR}${PREFIX}/lib/xmms/General/
	@${INSTALL_DATA} ${WRKSRC}/alert.wav ${STAGEDIR}${PREFIX}/lib/xmms/General/

.include <bsd.port.mk>
