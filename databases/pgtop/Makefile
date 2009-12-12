# New ports collection makefile for:	pgtop
# Date created:				30 May 2006
# Whom:					Bartek Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	pgtop
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CO/COSIMO

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Display PostgreSQL performance info like top(1)

RUN_DEPENDS=	p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DBD-Pg>=1.22:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.16:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN1=	pgtop.1

.include <bsd.port.mk>
