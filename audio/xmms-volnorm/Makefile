# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	volnorm
PORTVERSION=	0.8.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Volume Normalizer plugin for XMMS

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2

LIB_DEPENDS=	libxmms.so:multimedia/xmms

USES=		libtool
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	lib/xmms/Effect/libnormvol.so

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|tests||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^COMMON/s|-O2|@CFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xmms/Effect/libnormvol.so

.include <bsd.port.mk>
