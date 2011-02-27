# New ports collection makefile for:	graphics/xmms-waterfall
# Date created:			17 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	waterfall
PORTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.sethoscope.net/waterfall/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another XMMS spectrum analyzer

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Visualization/libwaterfall.la \
		lib/xmms/Visualization/libwaterfall.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
