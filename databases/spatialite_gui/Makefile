# New ports collection makefile for:	spatialite-gui
# Date created:		2012-06-14
# Whom:			lbartoletti <coder@tuxfamily.org>
#
# $FreeBSD$
#

PORTNAME=	spatialite_gui
PORTVERSION=	1.5.0
CATEGORIES=	databases
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Graphical User Interface (GUI) tool supporting SpatiaLite

LIB_DEPENDS=	gaiagraphics:${PORTSDIR}/graphics/libgaiagraphics \
		freexl:${PORTSDIR}/textproc/freexl \
		spatialite:${PORTSDIR}/databases/spatialite

USE_WX=		2.8
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include `${WX_CONFIG} --cppflags`
LDFLAGS+=	-L${LOCALBASE}/lib -liconv `${WX_CONFIG} --libs`
CONFIGURE_ARGS+=CFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/spatialite_gui

.include <bsd.port.mk>
