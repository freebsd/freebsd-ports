# New ports collection makefile for:    azrael
# Date created:				25 Aug 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	azrael
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	azrael

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	A GTK2 based XMMS2 client, offering a media library interface

BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

PLIST_FILES=bin/azrael

.include <bsd.port.mk>
