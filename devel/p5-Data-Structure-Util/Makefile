# New ports collection makefile for:	p5-Data-Structure
# Date created:		April 9 2006
# Whom:			Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Structure-Util
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	Perl5 module to change the nature of data within a structure

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=	yes

MAN1=		packages.pl.1
MAN3=		Data::Structure::Util.3

.include <bsd.port.mk>
