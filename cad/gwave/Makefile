# New ports collection makefile for:	gwave
# Date created:			16 June 2002
# Whom:				Duncan Barclay <dmlb@dmlb.org>
#
# $FreeBSD$
#

PORTNAME=	gwave
PORTVERSION=	20030804
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/ \
		http://geda.seul.org/dist/

MAINTAINER=	dmlb@dmlb.org
COMMENT=	Waveform viewer for analogue electronic simulation tools

RUN_DEPENDS=	graph:${PORTSDIR}/graphics/plotutils
LIB_DEPENDS=	geda.18:${PORTSDIR}/cad/libgeda \
		guile.15:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk

USE_AUTOCONF_VER=	253
USE_GNOME=	gtk12
#CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		sp2sp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.include <bsd.port.post.mk>
