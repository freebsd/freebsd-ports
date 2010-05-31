# New ports collection makefile for:   gtkdps
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gtkdps
PORTVERSION=	0.3.4
PORTREVISION=	6
CATEGORIES=	graphics
#		ftp://ftp.gyve.org/pub/gtkDPS/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Gtk bindings for the Display GhostScript System

LIB_DEPENDS+=	dpstk.0:${PORTSDIR}/x11/dgs

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dps-includes=${LOCALBASE}/include \
		--with-dps-libraries=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
