# New ports collection makefile for:	p5-Module-Info-File
# Date created:		2004-07-24
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Info-File
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Retrieves module information from a file or script

BUILD_DEPENDS=	${SITE_PERL}/Module/Info.pm:${PORTSDIR}/devel/p5-Module-Info
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		version.pl.1
MAN3=		Module::Info::File.3

.include <bsd.port.mk>
