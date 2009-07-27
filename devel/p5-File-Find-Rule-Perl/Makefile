# New ports collection makefile for:	devel/p5-File-Find-Rule-Perl
# Date created:				13 October 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Find-Rule-Perl
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	File::Find::Rule::Perl - Common rules for searching for Perl things

RUN_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Parse-CPAN-Meta>=0:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	File::Find::Rule::Perl.3

.include <bsd.port.mk>
