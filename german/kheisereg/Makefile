# New ports collection makefile for:	kheisereg
# Date created:			Tue Nov 11 00:06:12 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kheisereg
PORTVERSION=		0.8
PORTREVISION=	6
CATEGORIES=		german kde
MASTER_SITES=		http://www.gantz-edv.de/kheisereg/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		KDE utility to search within the Heise Register

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure

USE_BZIP2=		yes
USE_KDEBASE_VER=	3
USE_AUTOTOOLS=		libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/mnt|/cdrom|g' ${WRKSRC}/kheisereg/global.h

.include <bsd.port.mk>
