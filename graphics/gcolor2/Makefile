# Created by: Piotr Smyrak, piotr.smyrak@heron.pl
# $FreeBSD$

PORTNAME=	gcolor2
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Simple GTK+ 2.0 color selector

USES=		pkgconfig
USE_GNOME=	gtk20 gnomeprefix intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	gcolor2.desktop

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcolor2.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
