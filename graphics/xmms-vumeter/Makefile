# New ports collection makefile for:	xmms-vumeter
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	vumeter
PORTVERSION=	0.9.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}plugin
PKGNAMEPREFIX=	xmms-

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Analog VUmeter plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

SKINSDIR=	${PREFIX}/share/xmms/VU_Meter_skins
PLIST_SUB=	SKINSDIR="${SKINSDIR:S,^${PREFIX}/,,}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/src/vumeter.h

post-install:
.for s in default default.mirror default.oldxmms
	${MKDIR} ${SKINSDIR}/${s}
	${INSTALL_DATA} ${WRKSRC}/skins/${s}/* ${SKINSDIR}/${s}
.endfor

.include <bsd.port.mk>
