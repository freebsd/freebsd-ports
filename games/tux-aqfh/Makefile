# Created by: Alexander Langer <alex@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/tuxaqfh/tuxaqfh/${PORTVERSION}-classic \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Tuxedo The Penguin: A Quest for Herring

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USES=		gmake
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lusbhid ${PTHREAD_LIBS}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGES README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.png *.html

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Tuxedo The Penguin: A Quest for Herring" "" ${PORTNAME} \
		"${PORTNAME}" "Game;SportsGame;" ""

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

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
