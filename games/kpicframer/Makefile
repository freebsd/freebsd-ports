# New ports collection Makefile for:	kpicframer
# Date created:				2004-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpicframer
PORTVERSION=	0.5
PORTREVISION=	13
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE card game

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool
USE_GMAKE=		yes

pre-build:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
