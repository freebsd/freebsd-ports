# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	efax-gtk
PORTVERSION=	3.2.12
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	SF
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GUI frontend for efax program

LICENSE=	GPLv2

LIB_DEPENDS=	libsigc-1.2.so:${PORTSDIR}/devel/libsigc++12 \
		libcxx-gtk-utils-2-2.2.so:${PORTSDIR}/x11-toolkits/c++-gtk-utils
RUN_DEPENDS=	ggv:${PORTSDIR}/print/ggv

USES=		pkgconfig
USE_GHOSTSCRIPT_RUN=yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GCC=	yes

CONFLICTS=	efax-[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread -lintl

CONFIGURE_ARGS+=--with-gtk-version=gtk2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

.include <bsd.port.mk>
