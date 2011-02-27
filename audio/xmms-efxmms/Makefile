# New ports collection makefile for:	audio/xmms-efxmms
# Date created:			17 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-efxmms
PORTVERSION=	0.0.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/efxmms/EFXmms/EFXmms%20${PORTVERSION}
DISTNAME=	EFXmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send the XMMS audio output through a queue of multiple effect plugins

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Effect/libefx.la \
		lib/xmms/Effect/libefx.so

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
