# New ports collection makefile for:	dragstack
# Date created:			Thu Oct 30 23:18:04 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		dragstack
PORTVERSION=		1.3
PORTREVISION=	1
CATEGORIES=		deskutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Drop stack applet for KDE

USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
