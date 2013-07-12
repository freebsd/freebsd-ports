# Created by: Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
# $FreeBSD$

PORTNAME=	geeqie
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_GNOME=	gtk20 desktopfileutils
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--with-htmldir="${DOCSDIR}/html" \
		--with-readmedir="${DOCSDIR}"
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	${CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	top_builddir="${WRKSRC}"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
MAN1=		geeqie.1
USES=		gettext

OPTIONS_DEFINE=	EXIV2 LCMS LIRC GPS DOCS
OPTIONS_DEFAULT=EXIV2 LCMS
EXIV2_DESC=	Metadata editing
LCMS_DESC=	Color adjusting
LIRC_DESC=	Remote control
GPS_DESC=	GPS map support (libchamplain) EXPERIMENTAL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv2
.else
CONFIGURE_ARGS+=--disable-exiv2
.endif

.if ${PORT_OPTIONS:MLCMS}
LIB_DEPENDS+=	lcms:${PORTSDIR}/graphics/lcms
CONFIGURE_ARGS+=--enable-lcms
.else
CONFIGURE_ARGS+=--disable-lcms
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	lirc_client:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
.endif

# Support for libchamplain is marked as experimental!
.if ${PORT_OPTIONS:MGPS}
LIB_DEPENDS+=	champlain-0.8:${PORTSDIR}/graphics/libchamplain
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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-helpDATA||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/,/^[a-z]/ s|install-readmeDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
