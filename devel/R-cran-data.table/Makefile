# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data.table
DISTVERSION=	1.11.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Extension of Data.frame

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11_i386=	unable to load datatable.so
BROKEN_FreeBSD_12_i386=	unable to load datatable.so

LIB_DEPENDS=	libomp.so:devel/openmp

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
