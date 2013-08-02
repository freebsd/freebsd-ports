# created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	IPC-Run-SafeHandles
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Safe guarding for IPC::Run(3)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=	IPC::Run::SafeHandles.3

PLIST_DIRS=	%%SITE_PERL%%/IPC/Run \
			%%SITE_PERL%%/IPC \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run/SafeHandles \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC

PLIST_FILES=	%%SITE_PERL%%/IPC/Run/SafeHandles.pm \
				%%SITE_PERL%%/%%PERL_ARCH%%/auto/IPC/Run/SafeHandles/.packlist

.include <bsd.port.mk>
