# New ports collection makefile for:	passepartout
# Date created:				11st Sep 2003
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/passepartout/Makefile,v 1.4 2006/09/30 15:31:05 ahze Exp $

PORTNAME=	passepartout
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.stacken.kth.se/project/pptout/files/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20 \
		xml\\+\\+-1.0:${PORTSDIR}/textproc/libxml++
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFALGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=	xml2ps.1 passepartout.1x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-old_cxx
.endif

.if exists(${LOCALBASE}/lib/libfam.a)
WITH_FAM=	yes
.endif

.if defined(WITH_FAM)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

.include <bsd.port.post.mk>
