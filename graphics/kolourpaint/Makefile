# New ports collection makefile for:	kolourpaint
# Date created:			Fri May  7 10:13:12 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kolourpaint
PORTVERSION=	1.0.2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Paint program for KDE

LIB_DEPENDS=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		lcms:${PORTSDIR}/graphics/lcms

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|^tagnames=|#tagnames=|g;' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
