# New ports collection makefile for:    gxmms2
# Date created:				03 Mar 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	gxmms2
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://wejp.k.vu/projects/xmms2/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	A GTK2 based XMMS2 client, written in C

BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

USE_GNOME=	gtk20
USE_GMAKE=	yes

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/gxmms2 \
		%%DATADIR%%/gxmms2_mini.xpm
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gxmms2src/gxmms2_mini.xpm ${DATADIR}

.include <bsd.port.post.mk>
