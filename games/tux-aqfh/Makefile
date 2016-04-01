# Created by: Alexander Langer <alex@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/tuxaqfh/tuxaqfh/${PORTVERSION}-classic \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tuxedo The Penguin: A Quest for Herring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib

USES=		gmake
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lusbhid -pthread

PORTDOCS=	*

DESKTOP_ENTRIES="Tuxedo The Penguin: A Quest for Herring" "" ${PORTNAME} \
		"${PORTNAME}" "Game;SportsGame;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lplibul|-lplibul -lplibjs|; \
		 s|-O6 -Wall||; \
		 s|-lpthread||; \
		 s|datadir/games|datadir|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/games|@bindir@|; \
		 s|$$(datadir)/games|$$(datadir)|'
	@${REINPLACE_CMD} -e 's|doc contrib| contrib|' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"AUTHORS CHANGES README doc/*.png doc/*.html" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
