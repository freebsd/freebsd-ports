# New ports collection makefile for:	p5-DateTime-Fiscal-Year
# Date created:	   3 october 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Fiscal-Year
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate the day or week of the Fiscal Year with an arbitrary start date

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DateTime::Fiscal::Year.3

.include <bsd.port.mk>
