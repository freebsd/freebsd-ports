# New ports collection makefile for:	libticables
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticables
PORTVERSION=	3.9.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=		SF/tilp/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TI calculator link cables library

DEPRECATED=     Superseded by comms/libticables2
EXPIRATION_DATE=2013-07-01

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext
USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
.endif

.include <bsd.port.post.mk>
