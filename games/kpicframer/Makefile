# New ports collection Makefile for:	kpicframer
# Date created:				2004-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpicframer
PORTVERSION=	0.5
PORTREVISION=	12
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE card game

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool:22
USE_GMAKE=		yes

pre-build:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
