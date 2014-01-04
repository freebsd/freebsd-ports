# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/graphics/passepartout/Makefile,v 1.4 2006/09/30 15:31:05 ahze Exp $

PORTNAME=	passepartout
PORTVERSION=	0.7.1
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook2html:${PORTSDIR}/textproc/docbook-utils \
    		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USES=	pathfix gmake pkgconfig
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xml2ps.1 passepartout.1x

NO_STAGE=	yes

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libfam.a) || defined(WITH_FAM)
USES+=		fam
.endif

.include <bsd.port.mk>
