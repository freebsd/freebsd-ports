# New ports collection makefile for:	bookreader
# Date created:		2007-06-22
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	bookreader
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/k${PORTNAME}/
DISTNAME=	k${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE twin-panel e-text/e-book viewer

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
