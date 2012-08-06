# New ports collection makefile for:	p5-IO-Compress-Lzop
# Date created:		2011-02-13
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Lzop
PORTVERSION=	2.055
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write lzop files / buffers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-LZO>=0:${PORTSDIR}/archivers/p5-Compress-LZO \
		p5-IO-Compress>=2.052:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS=	p5-Compress-LZO>=0:${PORTSDIR}/archivers/p5-Compress-LZO \
		p5-IO-Compress>=2.052:${PORTSDIR}/archivers/p5-IO-Compress

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		IO::Compress::Lzop.3 IO::Uncompress::UnLzop.3

.include <bsd.port.mk>
