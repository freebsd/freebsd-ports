# New ports collection makefile for:	Log-Dispatch-Configurator-YAML
# Date created:				28 May 2008
# Whom:					Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	DBICx-TxnInsert
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VO/VOVKASM
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Wrap all inserts into transaction

RUN_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBD-Mock>=0:${PORTSDIR}/databases/p5-DBD-Mock \
		p5-ExtUtils-MakeMaker>=6.52:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBICx::TxnInsert.3

.include <bsd.port.mk>
