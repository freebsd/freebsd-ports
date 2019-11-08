# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-alarm
PORTVERSION=	11.8.16
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alarm plugin for gmpc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake gnome libtool pkgconfig
USE_GNOME=	glib20 gtk20 intltool
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
