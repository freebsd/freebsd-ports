# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	0.17
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/archive/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20 \
		gc.1:${PORTSDIR}/devel/boehm-gc

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--program-transform-name=\'\'
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		mcs.1 mint.1 mono.1 monoburg.1 monodis.1 monostyle.1 \
       		sqlsharpcli.1
MAN5=		mono-config.5

post-patch:
	@${REINPLACE_CMD} -e 's|<gc.h|<'${LOCALBASE}/'include/gc.h|g' \
		${WRKSRC}/mono/os/gc_wrapper.h

.include <bsd.port.mk>
