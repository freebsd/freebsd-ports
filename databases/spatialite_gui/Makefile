# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	spatialite_gui
PORTVERSION=	1.5.0
PORTREVISION=	2
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
USES=		pkgconfig iconv
CPPFLAGS+=	-I${LOCALBASE}/include `${WX_CONFIG} --cppflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} `${WX_CONFIG} --libs`
CONFIGURE_ARGS+=CFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/spatialite_gui

NO_STAGE=	yes
.include <bsd.port.mk>
