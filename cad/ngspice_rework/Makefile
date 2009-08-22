# New ports collection makefile for:	ngspice_rework
# Date created:		2002-01-02
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ngspice_rework
PORTVERSION=	18
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ng-spice-rework-${PORTVERSION}

MAINTAINER=	amakawa@jp.FreeBSD.org
COMMENT=	A circuit simulator derived from spice3f5

USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes

#XSPICE doesn't build
#CONFIGURE_ARGS+=	--enable-xspice

.ifndef PACKAGE_BUILDING
CONFIGURE_ARGS+=	--with-readline=yes
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

INFO=		ngspice
MAN1=		ngspice.1 ngnutmeg.1 ngsconvert.1 ngmultidec.1

.include <bsd.port.mk>
