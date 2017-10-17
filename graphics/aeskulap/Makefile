# Created by: gahr
# $FreeBSD$

PORTNAME=	aeskulap
PORTVERSION=	0.2.2.20140119
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24\
		libdcmimage.so:devel/dcmtk

USE_GITHUB=	yes
GH_ACCOUNT=	pipelka
GH_TAGNAME=	ea0a119

USES=		compiler:c++11-lang autoreconf desktop-file-utils gettext gmake \
		libtool localbase pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gconfmm26 gtkmm24 intltool
GCONF_SCHEMAS=	aeskulap.schemas
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes


.include <bsd.port.mk>
