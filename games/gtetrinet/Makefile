# New ports collection makefile for:	gtetrinet
# Date created:				27 Feb 2000
# Whom:					Dan Papasian <bugg@bugg.strangled.net>
#
# $FreeBSD$

PORTNAME=	gtetrinet
PORTVERSION=	0.4.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtetrinet

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 gnomehack gnomeprefix esound gnomelibs gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--bindir=${PREFIX}/bin

MAN6=		gtetrinet.6

do-install:
	cd ${WRKSRC}/src; ${INSTALL_PROGRAM} gtetrinet ${PREFIX}/bin
	cd ${WRKSRC}/doc; ${INSTALL_MAN} gtetrinet.6 ${PREFIX}/man/man6
	${MKDIR} ${PREFIX}/share/gnome/gtetrinet/themes/default
	cd  ${WRKSRC}/themes/default/; ${INSTALL_DATA} blocks.png theme.cfg \
		${PREFIX}/share/gnome/gtetrinet/themes/default
	${MKDIR} ${PREFIX}/share/gnome/gtetrinet/themes/small
	cd  ${WRKSRC}/themes/small/; ${INSTALL_DATA} blocks.png theme.cfg \
		${PREFIX}/share/gnome/gtetrinet/themes/small
	cd ${WRKSRC}; ${INSTALL_DATA} gtetrinet.png \
		${PREFIX}/share/gnome/pixmaps
	cd ${WRKSRC}; ${INSTALL_DATA} gtetrinet.desktop \
		${PREFIX}/share/gnome/apps/Games

.include <bsd.port.mk>
