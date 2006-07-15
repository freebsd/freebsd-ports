# New ports collection makefile for:	Class-DBI-Plugin-Senna
# Date created:		18 Feb 2006
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-Senna
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Add Instant Fulltext Search Capability With Senna to Class::DBI

BROKEN=		fails to install with coredump

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
	${SITE_PERL}/${PERL_ARCH}/Senna.pm:${PORTSDIR}/textproc/p5-Senna

PERL_CONFIGURE=	yes
MAN3=		Class::DBI::Plugin::Senna.3

.include <bsd.port.mk>
