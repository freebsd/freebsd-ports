# New ports collection makefile for:	xmms-faad
# Date created:			23 Feb, 2002
# Whom:				David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	xmms-

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS plugin for faad

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		xmms.4:${PORTSDIR}/multimedia/xmms \
		faad.0:${PORTSDIR}/audio/faad

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=

WRKSRC=		${WRKDIR}/${PORTNAME}/plugins/xmms

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/faad/distinfo
PLIST_FILES=	lib/xmms/Input/libaac-XMMS.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|${CC} ${CFLAGS} -fPIC|; \
		s|-I/usr/include/glib-1.2/||; \
		s|-lfaad2|-lfaad -lstdc++|; \
		s|-I/usr/lib/glib/include|-L${LOCALBASE}/lib|; \
		s|-I/usr/include/gtk-1.2/|\`xmms-config --cflags\`|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libaac-XMMS.so ${PREFIX}/lib/xmms/Input/

.include <bsd.port.mk>
