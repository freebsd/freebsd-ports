# New ports collection makefile for:	metabar
# Date created:				Fri Feb 25 15:44:58 CET 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	metabar
PORTVERSION=	0.6
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Sidebar plugin for Konqueror

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_KDEBASE_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
