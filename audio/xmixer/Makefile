# New ports collection makefile for:	xmixer
# Date created:		27 October 1999
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	xmixer
PORTVERSION=	0.9.3
CATEGORIES=	audio
MASTER_SITES=	http://www.hdk-berlin.de/~rasca/
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	trevor@jpj.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN1=		xmixer.1

post-extract:
	@${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
