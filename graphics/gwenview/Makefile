# New ports collection makefile for:	gwenview
# Date created:		22 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gwenview
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	An image viewer and browser for the KDE environment

LIB_DEPENDS=	kipi.0:${PORTSDIR}/graphics/libkipi

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=	--enable-kipi

MAN1=	gwenview.1

post-patch:
	@${TOUCH} -t 200504010000 ${WRKSRC}/Makefile.am.in
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
