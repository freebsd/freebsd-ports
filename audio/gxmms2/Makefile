# New ports collection makefile for:    gxmms2
# Date created:				03 Mar 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	gxmms2
PORTVERSION=	0.7.1
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	mad@madpilot.net
COMMENT=	A GTK2 based XMMS2 client, written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	xmmsclient.6:${PORTSDIR}/audio/xmms2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/gxmms2 \
		%%DATADIR%%/gxmms2_mini.xpm
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gxmms2src/gxmms2_mini.xpm ${DATADIR}

.include <bsd.port.post.mk>
