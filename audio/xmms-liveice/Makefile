# New ports collection makefile for:	xmms-liveice
# Date created:			5 Febrary 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-liveice
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/
DISTNAME=	liveice-xmms

MAINTAINER=	esk@ira.uka.de
COMMENT=	Use XMMS for streaming audio to Icecast servers

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

WRKSRC=		${WRKDIR}/LiveIce-1.0.0

PLIST_FILES=	lib/xmms/Effect/libliveice.so
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=	13

.include <bsd.port.mk>
