# New ports collection makefile for:	p5-IO-Compress-Lzf
# Date created:		2011-02-13
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Lzf
PORTVERSION=	2.037
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write lzf files/buffers

BUILD_DEPENDS=	p5-Compress-LZF>=0:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-IO-Compress>=2.037:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS=	p5-Compress-LZF>=0:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-IO-Compress>=2.037:${PORTSDIR}/archivers/p5-IO-Compress

PERL_CONFIGURE=	yes

MAN3=		IO::Compress::Lzf.3 IO::Uncompress::UnLzf.3

.include <bsd.port.mk>
