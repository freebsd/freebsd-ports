# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/librsvg2/Makefile,v 1.136 2010/11/13 12:59:46 kwm Exp $
#

PORTNAME?=	librsvg2
PORTVERSION=	2.32.1
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/librsvg/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gnomeprefix libgsf ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--with-croco \
		--enable-gtk-theme
CROCO_VERSION=	0.6

.if defined(SLAVEPORT)
USE_GNOME+=	librsvg2 gtk30
RUN_DEPENDS=	gtk-engines3>=2.90.3.1:${PORTSDIR}/x11-themes/gtk-engines3
.else
USE_GNOME+=	gtk20
RUN_DEPENDS=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2
MAN1=		rsvg.1
.endif

.include <bsd.port.pre.mk>

.if defined(SLAVEPORT)
post-patch:
	@${REINPLACE_CMD} -e 's|GTK2_REQUIRED=2.16.0|GTK2_REQUIRED=9.16.0|g' \
		${WRKSRC}/configure

do-build:
	@cd ${WRKSRC} && gmake rsvg-view-3
	@cd ${WRKSRC}/gtk-engine && gmake 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsvg-view-3 ${PREFIX}/bin
	@cd ${WRKSRC}/gtk-engine && gmake install
	
.else
post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=2.90.0|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
