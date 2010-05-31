# New ports collection makefile for:	gqview
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	2.0.4
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Another gtk2-based graphic file viewer

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehier gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAKE_JOBS_SAFE=	yes

MAN1=		gqview.1

CONFLICTS=	gqview-devel-[0-9]*

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$prefix/share/doc/gqview-$$VERSION|${DOCSDIR}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/gqview-$$(VERSION)/html|${DOCSDIR}/html|g' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's| -r %F||' \
		${WRKSRC}/gqview.desktop
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc$$||' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/gqview.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
