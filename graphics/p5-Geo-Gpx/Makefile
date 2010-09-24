# New ports collection makefile for:	p5-Geo-Gpx
# Date created:      			10 March 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-Gpx
PORTVERSION=	0.26
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl Module to Create and Parse GPX Files

BUILD_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-ExtUtils-MakeMaker-Coverage>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker-Coverage \
		p5-Time-Local>=0:${PORTSDIR}/devel/p5-Time-Local \
		p5-XML-Descent>=0:${PORTSDIR}/textproc/p5-XML-Descent
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Geo::Gpx.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
