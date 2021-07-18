# Created by: Alexander Langer <alex@FreeBSD.org>

PORTNAME=	tuxkart
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://tuxkart.sourceforge.net/dist/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Racing game starring Tux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib

USES=		gl gmake
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lusbhid

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="TuxKart" "" ${PORTNAME} \
		"${PORTNAME}" "Game;SportsGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|-O6||g ; s|datadir/games|datadir|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|$$(prefix)/games|@bindir@|g ; \
		 s|$$(datadir)/games|$$(datadir)|g'
	@${REINPLACE_CMD} -e 's|doc contrib| contrib|' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS CHANGES README doc/*.png doc/*.html" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
