# New ports collection makefile for:	kuake
# Date created:			Thu Mar 11 21:51:00 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kuake
PORTVERSION=	0.3
CATEGORIES=	deskutils kde
MASTER_SITES=	http://199.231.140.154/software/${PORTNAME}/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	KDE konsole application acting like the Quake-console

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
