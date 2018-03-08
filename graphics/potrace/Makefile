# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	potrace
DISTVERSION=	1.15
CATEGORIES=	graphics
MASTER_SITES=	SF/potrace/${PORTVERSION}

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Transforms bitmaps into vector graphics

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	METRIC A4 LIBRARY DOCS
OPTIONS_DEFAULT=METRIC A4
OPTIONS_SUB=	yes

METRIC_DESC=	Use metric units (cm) as default
METRIC_CONFIGURE_ENABLE=	metric
A4_DESC=	Use A4 as the default papersize
A4_CONFIGURE_ENABLE=	a4
LIBRARY_DESC=	Enable building libpotrace
LIBRARY_CONFIGURE_WITH=	libpotrace
LIBRARY_USE=	LDCONFIG=yes
LIBRARY_USES=	libtool
LIBRARY_INSTALL_TARGET=	install-strip

CONFLICTS=	libpotrace-*

.include <bsd.port.mk>
