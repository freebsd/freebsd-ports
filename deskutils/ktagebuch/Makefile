# New ports collection makefile for:	ktagebuch
# Date created:			Mon Nov 17 15:37:28 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		ktagebuch
PORTVERSION=		0.72
PORTREVISION=	1
CATEGORIES=		deskutils kde
MASTER_SITES=		http://home.tiscali.de/rainerb/ktagebuch/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		A diary program for KDE 3

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
