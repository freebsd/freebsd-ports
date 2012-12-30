# Ports collection makefile for:	kpum
# Date created:			Jun 18, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kpum
PORTVERSION=	0.5.3.1
PORTREVISION=	7
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE pureftpd user manager

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

.include <bsd.port.mk>
