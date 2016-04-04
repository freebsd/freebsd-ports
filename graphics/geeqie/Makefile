# Created by: Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
# $FreeBSD$

PORTNAME=	geeqie
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gettext gmake pkgconfig desktop-file-utils
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--with-htmldir="${DOCSDIR}/html" \
		--with-readmedir="${DOCSDIR}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	${CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	top_builddir="${WRKSRC}"

PORTDOCS=	*

OPTIONS_DEFINE=	EXIV2 LCMS LIRC GPS DOCS
OPTIONS_DEFAULT=EXIV2 LCMS
EXIV2_DESC=	Metadata editing
LCMS_DESC=	Color adjusting
LIRC_DESC=	Remote control
GPS_DESC=	GPS map support via libchamplain (experimental!)

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CONFIGURE_ENABLE=	exiv2

LCMS_LIB_DEPENDS=	liblcms.so:graphics/lcms
LCMS_CONFIGURE_ENABLE=	lcms

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc

GPS_LIB_DEPENDS=	libchamplain-0.8.so:graphics/libchamplain08
GPS_CONFIGURE_ENABLE=	gps

post-patch:
	@${REINPLACE_CMD} -e 's|champlain-0\.4|champlain-0.8|g; \
		s|champlain-gtk-0\.4|champlain-gtk-0.8|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|MAP_ANONYMOUS|MAP_ANON|' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's| -r %F||' ${WRKSRC}/geeqie.desktop
# I cannot get gnome-doc-tool working properly: Outputs gibberish
	@${REINPLACE_CMD} -Ee '/^(SUBDIRS|DIST_SUBDIRS)/ s|doc||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
