# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	five-or-more
PORTVERSION=	3.28.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Form a line of 5 or more colored balls

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share

GLIB_SCHEMAS=	org.gnome.five-or-more.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

.include <bsd.port.mk>
