# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	lostirc
PORTVERSION=	0.4.6
PORTREVISION=	15
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and minimal IRC client for X

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang gettext gnome pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kde

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS ChangeLog TODO README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
