# New ports collection makefile for:	passepartout
# Date created:				11st Sep 2003
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/passepartout/Makefile,v 1.4 2006/09/30 15:31:05 ahze Exp $
#

PORTNAME=	passepartout
PORTVERSION=	0.6.90
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	xml\\+\\+-1.0:${PORTSDIR}/textproc/libxml++ \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CFALGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=		xml2ps.1 passepartout.1x

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libfam.a)
WITH_FAM=	yes
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
.endif

.include <bsd.port.post.mk>
