# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-frontends
PORTVERSION=	1.0.14
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1140/ \
		ftp://ftp2.sane-project.org/pub/sane/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+

BROKEN=		unfetchable
DEPRECATED=	Unmaintained upstream, no consumers left
EXPIRATION_DATE=	2020-03-31

LIB_DEPENDS=	libsane.so:graphics/sane-backends

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GIMP

GIMP_DESC=	also build xscanimage as a GIMP plug-in

GIMP_CONFIGURE_ENABLE=	gimp
GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app

.include <bsd.port.mk>
