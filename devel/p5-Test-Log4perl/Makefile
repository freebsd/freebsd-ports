# New ports collection makefile for:	p5-Test-Log4perl
# Date created:				August 27, 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Log4perl
PORTVERSION=	0.1001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Log4perl - test Log::Log4perl

BUILD_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Lingua-EN-Numbers-Ordinate>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
		p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Log4perl.3

.include <bsd.port.mk>
