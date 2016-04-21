# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	volnorm
PORTVERSION=	0.8.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Volume Normalizer plugin for XMMS

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libxmms.so:multimedia/xmms

USES=		libtool
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	lib/xmms/Effect/libnormvol.so

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|tests||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^COMMON/s|-O2|@CFLAGS@|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
