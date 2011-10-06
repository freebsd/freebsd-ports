# New ports collection makefile for:	devel/p5-Git-Repository
# Date created:				Oct 19, 2010
# Whom:					Wen Heping<wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Git-Repository
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Git repositories

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-System-Command>=0:${PORTSDIR}/devel/p5-System-Command
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Git::Repository.3 \
		Git::Repository::Tutorial.3 \
		Git::Repository::Plugin::Log.3 \
		Git::Repository::Plugin.3 \
		Git::Repository::Log::Iterator.3 \
		Git::Repository::Log.3 \
		Git::Repository::Command.3 \
		Test::Git.3

.include <bsd.port.mk>
