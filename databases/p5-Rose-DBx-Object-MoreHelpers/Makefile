# New ports collection makefile for:	Rose-DBx-Object-MoreHelpers
# Date created:	   			23 Oct 2008
# Whom:		   			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rose-DBx-Object-MoreHelpers
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Rose/KARMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl 5 module to deploy a a DBIx::Class schema

RUN_DEPENDS=	p5-Rose-DB-Object>=0.7730,1:${PORTSDIR}/databases/p5-Rose-DB-Object \
		p5-Data-Dump>=1.06:${PORTSDIR}/devel/p5-Data-Dump

PERL_CONFIGURE=	yes

MAN3=		Rose::DBx::Object::MoreHelpers.3

.include <bsd.port.mk>
