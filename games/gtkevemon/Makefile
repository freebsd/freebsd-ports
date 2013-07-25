# $FreeBSD$

PORTNAME=	gtkevemon
DISTVERSION=	1.8-135
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/BattleClinic/${PORTNAME}/get/
DISTNAME=	Version%20${DISTVERSION}

MAINTAINER=	feld@freebsd.org
COMMENT=	A skill monitoring standalone application for EVE Online

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

FETCH_ARGS=	-pRr
CHANGESET=	8fa5c0b5f16b
WRKSRC=		${WRKDIR}/BattleClinic-${PORTNAME}-${CHANGESET}/${PORTNAME}

USES=		pkgconfig:both
USE_GNOME=	gtk20 libxml2
USE_GMAKE=	yes
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(shell pkg-config --libs openssl)|-L${OPENSSLLIB} -lssl -lcrypto|' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkevemon ${PREFIX}/bin/gtkevemon
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icon/gtkevemon.desktop ${PREFIX}/share/applications/gtkevemon.desktop
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icon/gtkevemon.png ${PREFIX}/share/pixmaps/gtkevemon.png

.include <bsd.port.post.mk>
