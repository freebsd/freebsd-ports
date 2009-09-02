# New ports collection makefile for:	gqview
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	2.1.5
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/unstable/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another gtk2-based graphic file viewer

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehier gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		gqview.1

CONFLICTS=	gqview-1.4* gqview-2.0*
LATEST_LINK=	gqview-devel

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix/share/doc/gqview-$$VERSION|${DOCSDIR}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/gqview-$$(VERSION)/html|${DOCSDIR}/html|g' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's| -r %F||' \
		${WRKSRC}/gqview.desktop
post-install:
	${MKDIR} ${PREFIX}/share/gnome/apps/Graphics
	${INSTALL_DATA} ${WRKSRC}/gqview.desktop ${PREFIX}/share/gnome/apps/Graphics
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gqview.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
