# New ports collection makefile for:	p5-DateTime-HiRes
# Date created:	   3 october 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-HiRes
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create DateTime objects with sub-second current time resolution

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_MODBUILD=	yes

MAN3=		DateTime::HiRes.3

.include <bsd.port.mk>
