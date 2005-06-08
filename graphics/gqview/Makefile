# New ports collection makefile for:	gqview
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	2.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Another gtk2-based graphic file viewer

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gtk20
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gqview.1

CONFLICTS=	gqview-devel-[0-9]*

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README html
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix/share/doc/gqview-$$VERSION|${DOCSDIR}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/gqview-$$(VERSION)/html|${DOCSDIR}/html|g' \
		${WRKSRC}/doc/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/gqview.desktop ${PREFIX}/share/gnome/apps/Graphics
	${INSTALL_DATA} ${WRKSRC}/gqview.png ${PREFIX}/share/gnome/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
