# New ports collection makefile for:	p5-Module-Pluggable
# Date created:		2004-07-26
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Pluggable
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Automatically give your module the ability to have plugins

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Devel::InnerPackage.3 \
		Module::Pluggable.3 \
		Module::Pluggable::Object.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or later. Please install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
