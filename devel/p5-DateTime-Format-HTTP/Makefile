# New ports collection makefile for:	p5-DateTime-Format-HTTP
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-HTTP
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP date conversion routines

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::HTTP.3

.include <bsd.port.mk>
