# New ports collection makefile for:	DBICx-Deploy
# Date created:	   			23 Oct 2008
# Whom:		   			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBICx-Deploy
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JR/JROCKWAY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl 5 module to deploy a a DBIx::Class schema

RUN_DEPENDS=	p5-DBIx-Class>=0.07003:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator

PERL_CONFIGURE=	yes

MAN1=	dbicdeploy.1
MAN3=	DBICx::Deploy.3

.include <bsd.port.mk>
