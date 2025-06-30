PORTNAME=	dia
PORTVERSION=	0.97.3
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Diagram creation program, similar to Visio
WWW=		https://wiki.gnome.org/Apps/Dia

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libicudata.so:devel/icu

USES=		cpe desktop-file-utils gettext gmake gnome libtool \
		localbase:ldflags pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gtk20 gnomeprefix libxslt libartlgpl2 intlhack

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-gnome
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

INSTALL_TARGET=	install-strip

LDFLAGS+=	`pkg-config --libs gmodule-2.0`

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

.include <bsd.port.options.mk>

#.if ${ARCH} == "i386"
#LIB_DEPENDS+=		libEMF.so:graphics/libemf
#CONFIGURE_ARGS+=	--enable-libemf
#PLIST_SUB+=		WMF=""
#.else
CONFIGURE_ARGS+=	--disable-libemf
PLIST_SUB+=		WMF="@comment "
#.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/lib/intl.c
	@${REINPLACE_CMD} -e 's|glib/gstrfuncs.h>|glib.h>|g' \
		-e 's|glib/gtestutils.h|glib.h|g' \
		${WRKSRC}/objects/custom/shape_typeinfo.c \
		${WRKSRC}/tests/test-objects.c \
		${WRKSRC}/tests/test-boundingbox.c
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e \
		's,\(^GTK_LIBS.*\),\1 -lpthread,'
	@${REINPLACE_CMD} -e 's|http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl|${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl| ; \
		s|/usr/include/libEMF|${LOCALBASE}/include/libEMF|g ; \
		s|-lstdc++||g'  ${WRKSRC}/configure

.include <bsd.port.mk>
