# ex:ts=8
# Ports collection makefile for:	kpum
# Date created:			Jun 18, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kpum
PORTVERSION=	0.5.3.1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE pureftpd user manager

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.mk>
