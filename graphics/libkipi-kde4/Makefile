# New ports collection makefile for:	libkipi
# Date created:				Mon Oct 18 19:41:36 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libkipi
PORTVERSION=	0.1.1
CATEGORIES=	graphics kde devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	digikam

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	KDE Image Plugin Interface

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
