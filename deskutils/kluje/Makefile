# New ports collection makefile for:	kluje
# Date created:				27 July 2003
# Whom:                                 Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	kluje
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jesse@gallup.com
COMMENT=	A KDE application for submitting updates to livejournal.com

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
