# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data.table
DISTVERSION=	1.12.6
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Extension of Data.frame

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	unable to load datatable.so

USES=		cran:auto-plist,compiles

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

.include <bsd.port.mk>
