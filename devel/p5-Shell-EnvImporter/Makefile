# New ports collection makefile for:   devel/p5-Shell-EnvImporter
# Date created:                                25 Aug 2006
# Whom:                                        Martin Jackson (mhjacks@swbell.net)
#
# $FreeBSD$
#

PORTNAME=	Shell-EnvImporter
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Inherit different shell environments, and restore previous

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker

PERL_CONFIGURE=	yes

MAN3=		Shell::EnvImporter.3 Shell::EnvImporter::Result.3 Shell::EnvImporter::Shell.3

.include <bsd.port.mk>
