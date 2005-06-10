# New ports collection makefile for:	audio/xmms-defx
# Date created:			7 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-defx
PORTVERSION=	0.9.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	defx

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Multi-effects processor plug-in for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

PLIST_FILES=	lib/xmms/Effect/libdefx.so

post-patch:
	@${REINPLACE_CMD} -e 's|^MAKE=.*||; s|gcc|${CC}|; s|-O2|${CFLAGS}|; \
		s|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/config.mak
	@${REINPLACE_CMD} -e 's|-shared|-shared -fPIC|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libdefx.so ${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>
