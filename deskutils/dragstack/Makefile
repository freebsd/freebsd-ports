# New ports collection makefile for:	dragstack
# Date created:			Thu Oct 30 23:18:04 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		dragstack
PORTVERSION=		1.4
PORTREVISION=	6
CATEGORIES=		deskutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Drop stack applet for KDE

USE_AUTOTOOLS=	libtool:15
USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
