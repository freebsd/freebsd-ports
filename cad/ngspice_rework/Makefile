# New ports collection makefile for:	ngspice_rework
# Date created:		2002-01-02
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ngspice_rework
PORTVERSION=	15
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ngspice
DISTNAME=	ngspice-rework${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amakawa@jp.FreeBSD.org
COMMENT=	A circuit simulator derived from spice3f5

WRKSRC=		${WRKDIR}/ng-spice-rework-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER?=15
USE_GMAKE=	yes

.ifndef PACKAGE_BUILDING
CONFIGURE_ARGS+=	--with-readline=yes
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

INFO=		ngspice
MAN1=		ngspice.1 ngnutmeg.1 ngsconvert.1

.include <bsd.port.mk>
