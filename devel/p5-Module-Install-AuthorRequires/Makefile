# New ports collection makefile for:	Module::Install::AuthorRequires
# Date created:		09 Sep 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Install-AuthorRequires
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to declare author-only dependencies

RUN_DEPENDS=	\
	p5-Module-Install>0:${PORTSDIR}/devel/p5-Module-Install
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Module::Install::AuthorRequires.3

.include <bsd.port.mk>
