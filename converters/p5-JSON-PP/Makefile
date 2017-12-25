# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-PP
PORTVERSION=	2.97001
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON::XS compatible pure-Perl module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

pre-patch:
	@${MV} ${WRKSRC}/bin/json_pp ${WRKSRC}/bin/p5json_pp
	@${REINPLACE_CMD} -e 's|bin/json_pp|bin/p5json_pp|' ${WRKSRC}/MANIFEST ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
