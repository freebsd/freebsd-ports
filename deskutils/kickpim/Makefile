# New ports collection makefile for:	kickpim
# Date created:			Mon Dec 29 16:29:43 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kickpim
PORTVERSION=		0.5.1
PORTREVISION=	1
CATEGORIES=		deskutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Panel applet for editing and accessing the KDE addressbook

USE_KDEBASE_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
