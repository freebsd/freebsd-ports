# New ports collection makefile for:	Data-ClearSilver-HDF
# Date created:	   14 Aug 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ClearSilver-HDF
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Convert from Perl Data Structure to ClearSilver HDF

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/ClearSilver.pm:${PORTSDIR}/www/p5-ClearSilver \
		${SITE_PERL}/${PERL_ARCH}/Data/Structure/Util.pm:${PORTSDIR}/devel/p5-Data-Structure-Util \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	cspage.1

MAN3=	Data::ClearSilver::HDF.3

.include <bsd.port.mk>
