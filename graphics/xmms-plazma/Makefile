# New ports collection makefile for:	xmms-plazma
# Date created:				15 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-plazma
DISTVERSION=	0.0.7
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://membres.lycos.fr/diablolight/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plazma is an XMMS visualization plugin

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GL=		yes
USE_GNOME=	gtk12
USE_SDL=	sdl
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Visualization/libplazma.a \
		lib/xmms/Visualization/libplazma.la \
		lib/xmms/Visualization/libplazma.so

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
