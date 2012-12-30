# New ports collection makefile for:	dragstack
# Date created:			Thu Oct 30 23:18:04 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		dragstack
PORTVERSION=		1.4
PORTREVISION=	10
CATEGORIES=		deskutils kde
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Drop stack applet for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_AUTOTOOLS=	libtool
USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
