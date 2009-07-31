# New ports collection makefile for:	gwenview
# Date created:		22 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gwenview
PORTVERSION=	1.4.2
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	An image viewer and browser for the KDE environment

LIB_DEPENDS=	kipi.2:${PORTSDIR}/graphics/libkipi \
		exiv2.7:${PORTSDIR}/graphics/exiv2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ARGS+=--enable-kipi

MAN1=	gwenview.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
