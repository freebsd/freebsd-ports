# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	vumeter
PORTVERSION=	0.9.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}plugin/Plugin%20for%20XMMS
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analog VUmeter plugin for XMMS

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/xmms/VU_Meter_skins

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/src/vumeter.h
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
.for s in default default.mirror default.oldxmms
	${MKDIR} ${DATADIR}/${s}
	${INSTALL_DATA} ${WRKSRC}/skins/${s}/* ${DATADIR}/${s}
.endfor

.include <bsd.port.mk>
