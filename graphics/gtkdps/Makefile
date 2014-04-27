# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	gtkdps
PORTVERSION=	0.3.4
PORTREVISION=	7
CATEGORIES=	graphics
#		ftp://ftp.gyve.org/pub/gtkDPS/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk bindings for the Display GhostScript System

LIB_DEPENDS=	libdpstk.so:${PORTSDIR}/x11/dgs

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dps-includes=${LOCALBASE}/include \
		--with-dps-libraries=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

alpha_BROKEN=	Does not compile on alpha

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|gnulocaledir)|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
