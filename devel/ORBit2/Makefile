# New ports collection makefile for:   orbit
# Version required:		0.4.93
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.19 1999/05/30 03:35:07 steve Exp $
#

DISTNAME=	ORBit-0.4.93
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/ORBit

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib12.2:${PORTSDIR}/devel/glib12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libIDL/configure popt/configure
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
CONFIGURE_ARGS= --disable-indent

.include <bsd.port.mk>
