# New ports collection makefile for:	p5-B-Deobfuscate
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	B-Deobfuscate
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension to B::Deparse for use in de-obfuscating source code

RUN_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/B/Keywords.pm:${PORTSDIR}/devel/p5-B-Keywords
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		B::Deobfuscate.3 B::Deobfuscate::Dict::Flowers.3 B::Deobfuscate::Dict::PGPHashWords.3

.include <bsd.port.mk>
