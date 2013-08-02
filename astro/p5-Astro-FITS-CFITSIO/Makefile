# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Astro-FITS-CFITSIO
PORTVERSION=	1.10
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for using the cfitsio library

LIB_DEPENDS=	cfitsio:${PORTSDIR}/astro/cfitsio

CONFIGURE_ENV=	CFITSIO=${LOCALBASE}
USES=		perl5
USE_PERL5=	configure

MAN3=		Astro::FITS::CFITSIO.3

.include <bsd.port.mk>
