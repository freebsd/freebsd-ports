PORTNAME=	gcolor2
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Simple GTK+ 2.0 color selector

LICENSE=	GPLv2

USES=		gnome pkgconfig
USE_GNOME=	gtk20 gnomeprefix intltool
GNU_CONFIGURE=	yes

SUB_FILES=	gcolor2.desktop

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcolor2.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
