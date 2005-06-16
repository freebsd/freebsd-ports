# New ports collection makefile for:	graphics/xmms-dflowers
# Date created:			15 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	dflowers
PORTVERSION=	1.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.shell.linux.se/bm/f/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^/v/}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Dual Flowers visualization plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-m486||; s|-O2||; \
		s|-Wall|-Wall ${CFLAGS}|; \
		s|gtk-config|${GTK_CONFIG}|; \
		s|install lib|${INSTALL_PROGRAM} lib|; \
		s|install bg|${INSTALL_DATA} bg|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
