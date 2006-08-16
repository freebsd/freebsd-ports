# New ports collection makefile for:	devel/p5-Module-CoreList
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-CoreList
PORTVERSION=	2.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	See what modules shipped with versions of perl

BUILD_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		corelist.1
MAN3=		Module::CoreList.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or later. Please install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
