# New ports collection makefile for:	xmms-liveice
# Date created:			5 Febrary 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-liveice
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/
DISTNAME=	liveice-xmms

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

WRKSRC=		${WRKDIR}/LiveIce-1.0.0

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
