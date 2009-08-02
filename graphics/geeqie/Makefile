# New ports collection makefile for:	graphics/geeqie
# Date created:				17 May 2008
# Whom:					Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
#
# $FreeBSD$
#

PORTNAME=	geeqie
DISTVERSION=	1.0alpha3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--with-htmldir="${DOCSDIR}/html" \
		--with-readmedir="${DOCSDIR}"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS+=	top_builddir="${WRKSRC}"

PORTDOCS=	*
MAN1=		geeqie.1
USE_GETTEXT=	yes

OPTIONS=	EXIV2 "Enable EXIV2 for metadata editing" on \
		LCMS "Enable LCMS for color adjusting" on
# Build fails with lirc enabled, disable it for now
#		LIRC "Enable lirc for remote control" off

.include <bsd.port.pre.mk>

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.7:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv2
.else
CONFIGURE_ARGS+=--disable-exiv2
.endif

.if defined(WITH_LCMS)
LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms
CONFIGURE_ARGS+=--enable-lcms
.else
CONFIGURE_ARGS+=--disable-lcms
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
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
