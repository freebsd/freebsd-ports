# New ports collection makefile for:   gtkdps
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gtkdps
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gtkDPS/
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk bindings for the Display GhostScript System

BUILD_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs
RUN_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs

USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
