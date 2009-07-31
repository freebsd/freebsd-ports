# New ports collection makefile for:	kio-p7zip
# Date created:				2006-07-28
# Whom:					makc <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kio_p7zip
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	archivers kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTNAME=	17829-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Kioslave for KDE to handle 7zip files

RUN_DEPENDS=	7za:${PORTSDIR}/archivers/p7zip

USE_BZIP2=	yes
USE_QT_VER=	3
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
