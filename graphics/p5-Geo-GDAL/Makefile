# New ports collection makefile for:	p5-Geo-GDAL
# Date created:		2012-03-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-GDAL
PORTVERSION=	1.9.1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	p5-
DISTNAME=	gdal-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl binding for GDAL

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/perl

post-patch:
	@${REINPLACE_CMD} -e 's| install| pure_install|' ${WRKSRC}/${MAKEFILE}

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} test || ${TRUE}

.include <bsd.port.mk>
