# New ports collection makefile for:	ngspice_rework
# Date created:		2002-01-02
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ngspice_rework
PORTVERSION=	17
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ngspice
DISTNAME=	ng-spice-rework-${PORTVERSION}

MAINTAINER=	amakawa@jp.FreeBSD.org
COMMENT=	A circuit simulator derived from spice3f5

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--disable-debug

INFO=		ngspice
MAN1=		ngspice.1 ngnutmeg.1 ngsconvert.1

.include <bsd.port.mk>
