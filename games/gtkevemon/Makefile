# $FreeBSD$

PORTNAME=	gtkevemon
PORTVERSION=	1.10.2016.02.17
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Skill monitoring standalone application for EVE Online

LIB_DEPENDS=	libgtkmm-3.0.so:x11-toolkits/gtkmm30 \
		libcurl.so:ftp/curl

USE_GITHUB=     yes
GH_TAGNAME=     ac2ca34

USES=		compiler:c++11-lang gmake gnome pkgconfig:both ssl
USE_CXXSTD=	c++11
USE_GNOME=	gtk30 libxml2

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(shell pkg-config --libs openssl)|-L${OPENSSLLIB} -lssl -lcrypto|' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkevemon ${STAGEDIR}${PREFIX}/bin/gtkevemon
	${INSTALL_DATA} ${WRKSRC}/icon/gtkevemon.desktop ${STAGEDIR}${PREFIX}/share/applications/gtkevemon.desktop
	${INSTALL_DATA} ${WRKSRC}/icon/gtkevemon.svg ${STAGEDIR}${PREFIX}/share/pixmaps/gtkevemon.svg

.include <bsd.port.post.mk>
