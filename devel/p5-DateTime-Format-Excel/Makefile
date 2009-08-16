# New ports collection makefile for:	p5-DateTime-Format-Excel
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Excel
PORTVERSION=	0.29.01
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert between DateTime and Excel dates

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::Excel.3

.include <bsd.port.mk>
