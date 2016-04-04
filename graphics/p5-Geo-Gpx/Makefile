# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-Gpx
PORTVERSION=	0.26
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Create and Parse GPX Files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-ExtUtils-MakeMaker-Coverage>=0:devel/p5-ExtUtils-MakeMaker-Coverage \
		p5-Time-Local>=0:devel/p5-Time-Local \
		p5-XML-Descent>=0:textproc/p5-XML-Descent \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
