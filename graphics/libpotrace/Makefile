# $FreeBSD$

PORTNAME=	libpotrace
PORTVERSION=	1.12
CATEGORIES=	graphics
MASTER_SITES=	SF/potrace/${PORTVERSION}
DISTNAME=	potrace-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for transforming bitmaps into vector graphics

LICENSE=	GPLv2

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpotrace
INSTALL_TARGET=	install-strip
PLIST_FILES=	include/potracelib.h \
		lib/libpotrace.a \
		lib/libpotrace.so \
		lib/libpotrace.so.0 \
		lib/libpotrace.so.0.0.2

OPTIONS_DEFINE=	METRIC A4
OPTIONS_DEFAULT=METRIC A4
A4_DESC=	Use A4 as the default papersize
A4_CONFIGURE_ENABLE=		a4
METRIC_DESC=	Use metric units (cm) as default
METRIC_CONFIGURE_ENABLE=	metric

.include <bsd.port.mk>
