# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	gtkdps
PORTVERSION=	0.3.4
PORTREVISION=	8
CATEGORIES=	graphics
#		ftp://ftp.gyve.org/pub/gtkDPS/
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk bindings for the Display GhostScript System

LIB_DEPENDS=	libdpstk.so:x11/dgs

USES=		libtool
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dps-includes=${LOCALBASE}/include \
		--with-dps-libraries=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} 's|gnulocaledir)|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtkDPS.so

.include <bsd.port.mk>
