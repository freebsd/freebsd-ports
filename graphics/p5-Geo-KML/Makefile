# New ports collection makefile for:	p5-Geo-KML
# Date created:      			10 January 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-KML
PORTVERSION=	0.03
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl Module to Create Google Earth KML/KMZ

RUN_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Archive-Zip>=1.18:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Log-Report>=0.18:${PORTSDIR}/devel/p5-Log-Report \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.14:${PORTSDIR}/textproc/p5-XML-Compile-Cache

MAN3=		Geo::KML.3 Geo::KML::Util.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
