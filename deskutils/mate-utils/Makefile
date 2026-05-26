PORTNAME=	mate-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.0
CATEGORIES=	deskutils mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+ GFDL LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.docs
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.libs

BUILD_DEPENDS=	itstool:textproc/itstool \
		gtkdocize:textproc/gtk-doc \
		${LOCALBASE}/share/aclocal/ax_require_defined.m4:devel/autoconf-archive \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools

LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
GH_TUPLE=	mate-desktop:mate-submodules:54fff1b:submodules/gsearchtool/mate-submodules
USES=		autoreconf gettext gmake gnome libtool localbase mate \
		pkgconfig xorg
USE_MATE=	panel common:build
USE_XORG=	ice sm x11 xext
USE_GNOME=	cairo gnomeprefix gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-disk-image-mounter \
		--disable-gtk-doc

GLIB_SCHEMAS=	org.mate.dictionary.gschema.xml \
		org.mate.disk-usage-analyzer.gschema.xml \
		org.mate.screenshot.gschema.xml \
		org.mate.search-tool.gschema.xml \
		org.mate.system-log.gschema.xml

.include <bsd.port.mk>
