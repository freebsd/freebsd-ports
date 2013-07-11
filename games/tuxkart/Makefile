# Created by: Alexander Langer <alex@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxkart
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://tuxkart.sourceforge.net/dist/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Racing game starring Tux

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lusbhid"
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGES README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.png *.html

DESKTOP_ENTRIES="TuxKart" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O6|${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|datadir/games|datadir|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/games|@bindir@|g ; \
		 s|$$(datadir)/games|$$(datadir)|g'
	@${REINPLACE_CMD} -e 's|doc contrib| contrib|' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
