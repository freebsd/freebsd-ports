# New ports collection makefile for:	plotutils
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $FreeBSD$
#

PORTNAME=	plotutils
PORTVERSION=	2.5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	stephen@missouri.edu
COMMENT=	A plotting library and toolkit

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget
USE_MOTIF=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi --with-motif
USE_LDCONFIG=	yes

MAN1=		ode.1 plot.1 plotfont.1 spline.1 tek2plot.1
INFO=		libxmi plotutils

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
