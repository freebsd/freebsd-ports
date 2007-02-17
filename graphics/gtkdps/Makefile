# New ports collection makefile for:   gtkdps
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gtkdps
PORTVERSION=	0.3.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gyve.org/pub/gtkDPS/	\
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Gtk bindings for the Display GhostScript System

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib
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

.if ${X_WINDOW_SYSTEM:L} == "xfree86-4"
BUILD_DEPENDS+=	pswrap:${PORTSDIR}/devel/imake-4
.else
BUILD_DEPENDS+=	pswrap:${PORTSDIR}/x11/dgs
LIB_DEPENDS+=	dpstk.0:${PORTSDIR}/x11/dgs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
