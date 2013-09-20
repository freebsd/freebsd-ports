# Created by: Bartek Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	pgtop
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:COSIMO

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Display PostgreSQL performance info like top(1)

RUN_DEPENDS=	p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DBD-Pg>=1.22:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.16:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

MAN1=	pgtop.1

NO_STAGE=	yes
.include <bsd.port.mk>
