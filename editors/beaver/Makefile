# New ports collection makefile for:	beaver
# Date created:			11 Apr 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		beaver
PORTVERSION=		0.3.1
PORTREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A programmer's text editor for GTK+ 2.0

USE_GNOME=		gtk20

USE_X_PREFIX=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

LIB_DEPENDS=		gtksourceview-1.0.0:${PORTSDIR}/x11-toolkits/gtksourceview

post-patch:
	@${REINPLACE_CMD} -e 's|/applications|/gnome/applications|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/pixmaps|/gnome/pixmaps|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
