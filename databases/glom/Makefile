# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glom
PORTVERSION=	1.28.0
PORTREVISION=	2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		libepc>=0.4.0:www/libepc \
		libgda5-mysql>=0:databases/libgda5-mysql \
		libgda5-postgresql>=0:databases/libgda5-postgresql
LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs \
		libepc-1.0.so:www/libepc \
		libgoocanvasmm-2.0.so:graphics/goocanvasmm2 \
		libevview3.so:graphics/evince
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		libgda5-mysql>=0:databases/libgda5-mysql \
		libgda5-postgresql>=0:databases/libgda5-postgresql

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake libarchive libtool pathfix \
		pgsql pkgconfig python shared-mime-info tar:xz
WANT_PGSQL=	server
USE_GNOME=	gnomedocutils gnomeprefix intlhack pygobject3 libxml2 \
		gtksourceviewmm3 libgdamm5
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin \
		--disable-documentation
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

#PLIST_SUB+=	VERSION=${PORTVERSION:R}
PLIST_SUB+=	VERSION=1.26

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|std::locale("")|std::locale()|g' \
		${WRKSRC}/glom/libglom/data_structure/glomconversions.cc \
		${WRKSRC}/glom/libglom/data_structure/glomconversions.h \
		${WRKSRC}/glom/libglom/utils.cc \
		${WRKSRC}/glom/mode_design/layout/layout_item_dialogs/comboentry_borderwidth.cc \
		${WRKSRC}/glom/mode_design/layout/layout_item_dialogs/dialog_group_by.cc \
		${WRKSRC}/glom/main.cc

.include <bsd.port.mk>
