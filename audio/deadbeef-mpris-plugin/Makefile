# New ports collection makefile for:	DeaDBeeF MPRIS plugin
# Date created:				18 Nov 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deadbeef-mpris-plugin
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MPRIS plugin for DeaDBeeF music player

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:${PORTSDIR}/audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GNOME=	glib20

WRKSRC=		${WRKDIR}/deadbeef-${PORTVERSION}

.include <bsd.port.mk>
