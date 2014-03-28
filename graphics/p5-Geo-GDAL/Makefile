# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-GDAL
PORTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	p5-
DISTNAME=	gdal-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl binding for GDAL

LICENSE=	MIT

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

USES=		perl5
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/perl

post-patch:
	@${REINPLACE_CMD} -e 's| install| pure_install|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|(const char \*)""|(char \*)""|' ${WRKSRC}/gdal_wrap.cpp ${WRKSRC}/ogr_wrap.cpp

post-install:
	${SED} -i '' 's|^${STAGEDIR}||' ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/GDAL/Const/.packlist ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/*/.packlist
	${CHMOD} u+w ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/GDAL/Const/Const.so ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/*/*.so
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/GDAL/Const/Const.so ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Geo/*/*.so

regression-test test: build
	-cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
