# New ports collection makefile for:	graphics/geeqie
# Date created:				17 May 2008
# Whom:					Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
#
# $FreeBSD$
#

PORTNAME=	geeqie
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--with-htmldir="${DOCSDIR}/html" \
		--with-readmedir="${DOCSDIR}"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS+=	top_builddir="${WRKSRC}"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
MAN1=		geeqie.1
USE_GETTEXT=	yes

OPTIONS=	EXIV2 "Metadata editing" on \
		LCMS "Color adjusting" on \
		LIRC "Remote control" off \
		GPS "GPS map support (libchamplain) EXPERIMENTAL" off

.include <bsd.port.pre.mk>

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.9:${PORTSDIR}/graphics/exiv2
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
LIB_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
.endif

# Support for libchamplain is marked as experimental!
.if defined(WITH_GPS)
LIB_DEPENDS+=	champlain-0.8.1:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-gps
.else
CONFIGURE_ARGS+=--disable-gps
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MAP_ANONYMOUS|MAP_ANON|' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's| -r %F||' ${WRKSRC}/geeqie.desktop
# I cannot get gnome-doc-tool working properly: Outputs gibberish
	@${REINPLACE_CMD} -Ee '/^(SUBDIRS|DIST_SUBDIRS)/ s|doc||' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-helpDATA||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/,/^[a-z]/ s|install-readmeDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
