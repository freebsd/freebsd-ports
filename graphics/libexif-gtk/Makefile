# New ports collection makefile for:	libexif-gtk
# Date created:		10 Jun 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libexif-gtk
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libexif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ widgets to display/edit EXIF tags

LIB_DEPENDS=	exif.10:${PORTSDIR}/graphics/libexif

USE_GNOME=	gnomehack gtk20
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
