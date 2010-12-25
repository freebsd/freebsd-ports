# New ports collection makefile for:	p5-Geo-KML
# Date created:      			10 January 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-KML
PORTVERSION=	0.92
CATEGORIES=	graphics perl5 geography
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Create Google Earth KML/KMZ

RUN_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Log-Report>=0.28:${PORTSDIR}/devel/p5-Log-Report \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-XML-Compile>=1.16:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.96:${PORTSDIR}/textproc/p5-XML-Compile-Cache

MAN3=		Geo::KML.3 Geo::KML::Util.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
