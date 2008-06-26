# New ports collection makefile for:	graphics/geeqie
# Date created:				17 May 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/graphics/geeqie/Makefile,v 1.2 2008/05/17 19:35:22 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	geeqie
DISTVERSION=	1.0alpha1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Lightweight image viewer forked from GQview

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--with-htmldir="${DOCSDIR}/html" \
		--with-readmedir="${DOCSDIR}"
MAKE_ARGS+=	top_builddir="${WRKSRC}"

PORTDOCS=	*

MAN1=		geeqie.1

OPTIONS=	EXIV2 "Enable EXIV2 for metadata editing" on \
		LCMS "Enable LCMS for color adjusting" on

.include <bsd.port.pre.mk>

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.3:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--with-exiv2
.else
CONFIGURE_ARGS+=--without-exiv2
.endif

.if defined(WITH_LCMS)
LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms
CONFIGURE_ARGS+=--with-lcms
.else
CONFIGURE_ARGS+=--without-lcms
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -r %F||' \
		${WRKSRC}/geeqie.desktop
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-helpDATA||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/,/^[a-z]/ s|install-readmeDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
