# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-frontends
PORTVERSION=	1.0.14
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	https://alioth-archive.debian.org/releases/sane/sane-frontends/${PORTVERSION}/ \
		https://www.ibiblio.org/pub/linux/apps/graphics/capture/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+

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
