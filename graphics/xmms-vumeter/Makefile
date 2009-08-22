# New ports collection makefile for:	xmms-vumeter
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	vumeter
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}plugin/${PORTNAME}plugin/VU%20meter%20v${PORTVERSION}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Analog VUmeter plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/xmms/VU_Meter_skins

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/src/vumeter.h
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
.for s in default default.mirror default.oldxmms
	${MKDIR} ${DATADIR}/${s}
	${INSTALL_DATA} ${WRKSRC}/skins/${s}/* ${DATADIR}/${s}
.endfor

.include <bsd.port.mk>
