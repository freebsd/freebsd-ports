# New ports collection makefile for:	p5-IO-Compress-Lzma
# Date created:		2010-07-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Lzma
PORTVERSION=	2.030
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Write lzma files/buffers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Raw/Lzma.pm:${PORTSDIR}/archivers/p5-Compress-Raw-Lzma \
		${SITE_PERL}/IO/Compress/Base.pm:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Raw/Lzma.pm:${PORTSDIR}/archivers/p5-Compress-Raw-Lzma \
		${SITE_PERL}/IO/Compress/Base.pm:${PORTSDIR}/archivers/p5-IO-Compress

PERL_CONFIGURE=	yes

MAN3=		IO::Compress::Lzma.3 IO::Compress::Xz.3 \
		IO::Uncompress::UnLzma.3 IO::Uncompress::UnXz.3

.include <bsd.port.mk>
