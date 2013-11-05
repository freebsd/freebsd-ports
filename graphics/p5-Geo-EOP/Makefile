# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-EOP
PORTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Process Earth Observation Products Meta-data

RUN_DEPENDS=	p5-Geo-GML>=0.12:${PORTSDIR}/graphics/p5-Geo-GML \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.14:${PORTSDIR}/textproc/p5-XML-Compile-Cache
TEST_DEPENDS=	p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
