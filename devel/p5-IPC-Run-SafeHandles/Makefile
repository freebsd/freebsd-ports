# New ports collection makefile for:	devele/p5-IPC-Run-SafeHandles
# Date created:				29 July 2008
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	IPC-Run-SafeHandles
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	IPC::Run::SafeHandles - Safe guarding for IPC::Run(3)

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=	IPC::Run::SafeHandles.3

PLIST_DIRS=	%%SITE_PERL%%/IPC/Run \
			%%SITE_PERL%%/IPC \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run/SafeHandles \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC

PLIST_FILES=	%%SITE_PERL%%/IPC/Run/SafeHandles.pm \
				%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run/SafeHandles/.packlist

.include <bsd.port.mk>
