# New ports collection makefile for:	kheisereg
# Date created:			Tue Nov 11 00:06:12 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kheisereg
PORTVERSION=		0.7
PORTREVISION=	1
CATEGORIES=		german kde
MASTER_SITES=		http://www.gantz-edv.de/kheisereg/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		KDE utility to search within the Heise Register

USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
