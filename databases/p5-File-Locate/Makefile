# $FreeBSD$

PORTNAME=	File-Locate
PORTVERSION=	0.62
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search the locate(1)-database from Perl

LICENSE=	GPLv2+

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_ARCH%%/File/Locate.pm \
		%%SITE_ARCH%%/auto/File/Locate/Locate.so \
		%%SITE_ARCH%%/auto/File/Locate/autosplit.ix \
		%%PERL5_MAN3%%/File::Locate.3.gz

.include <bsd.port.mk>
