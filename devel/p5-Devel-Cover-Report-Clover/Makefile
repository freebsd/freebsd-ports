# New ports collection makefile for:	Devel::Cover::Report::Clover
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-Cover-Report-Clover
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Clover reporting of coverage statistics

RUN_DEPENDS=	\
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Devel-Cover>0:${PORTSDIR}/devel/p5-Devel-Cover \
	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Devel::Cover::Report::Clover.3

.include <bsd.port.mk>
