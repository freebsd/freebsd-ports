# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-frontends
PORTVERSION=	1.0.14
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1140/ \
		ftp://ftp2.sane-project.org/pub/sane/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+

LIB_DEPENDS=	libsane.so:graphics/sane-backends

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GTK1 GIMP
GTK1_DESC=	GTK1 support (Default is GTK2)
GIMP_DESC=	also build xscanimage as a GIMP plug-in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK1}
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-gimp
.else
USE_GNOME+=	gtk20
.if ${PORT_OPTIONS:MGIMP}
LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app
CONFIGURE_ARGS+=	--enable-gimp
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif
.endif

.include <bsd.port.mk>
