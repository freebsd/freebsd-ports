# New ports collection makefile for:	p5-B-Deobfuscate
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	B-Deobfuscate
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Extension to B::Deparse for use in de-obfuscating source code

RUN_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/B/Keywords.pm:${PORTSDIR}/devel/p5-B-Keywords
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		B::Deobfuscate.3 B::Deobfuscate::Dict::Flowers.3 B::Deobfuscate::Dict::PGPHashWords.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601 # textproc/p5-YAML
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
