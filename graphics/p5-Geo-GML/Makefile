# New ports collection makefile for:	p5-Geo-GML
# Date created:      			11 January 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-GML
PORTVERSION=	0.14
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl Module to Process Geography Markup Language

RUN_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Log-Report>=0.18:${PORTSDIR}/devel/p5-Log-Report \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.14:${PORTSDIR}/textproc/p5-XML-Compile-Cache

MAN3=		Geo::GML.3 Geo::GML::Util.3 Geo::GML::GeoPoint.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
