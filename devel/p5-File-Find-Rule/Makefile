# New ports collection makefile for:	File-Find-Rule
# Date created:	   19 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	File-Find-Rule
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Alternative interface to File::Find

RUN_DEPENDS=	p5-Number-Compare>=0:${PORTSDIR}/math/p5-Number-Compare \
		p5-Text-Glob>=0:${PORTSDIR}/textproc/p5-Text-Glob

PERL_MODBUILD=	yes

MAN1=		findrule.1
MAN3=		File::Find::Rule.3 File::Find::Rule::Extending.3 \
		File::Find::Rule::Procedural.3

.include <bsd.port.mk>
