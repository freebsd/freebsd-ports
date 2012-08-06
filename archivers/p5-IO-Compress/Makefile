# New ports collection makefile for:	p5-IO-Compress
# Date created:		2010-09-10
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress
PORTVERSION=	2.055
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 compression modules (bzip2, deflate, gzip, zlib, zip)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Raw-Bzip2>=2.052:${PORTSDIR}/archivers/p5-Compress-Raw-Bzip2 \
		p5-Compress-Raw-Zlib>=2.052:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
RUN_DEPENDS=	p5-Compress-Raw-Bzip2>=2.052:${PORTSDIR}/archivers/p5-Compress-Raw-Bzip2 \
		p5-Compress-Raw-Zlib>=2.052:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

CONFLICTS=	p5-Compress-Zlib-2* p5-IO-Compress-Base-2* p5-IO-Compress-Zlib-2* p5-IO-Compress-Bzip2-2*

PERL_CONFIGURE=	yes

MAN1=		zipdetails.1
MAN3=		Compress::Zlib.3 \
		File::GlobMapper.3 \
		IO::Compress::Base.3 \
		IO::Compress::Bzip2.3 \
		IO::Compress::Deflate.3 \
		IO::Compress::FAQ.3 \
		IO::Compress::Gzip.3 \
		IO::Compress::RawDeflate.3 \
		IO::Compress::Zip.3 \
		IO::Uncompress::AnyInflate.3 \
		IO::Uncompress::AnyUncompress.3 \
		IO::Uncompress::Base.3 \
		IO::Uncompress::Bunzip2.3 \
		IO::Uncompress::Gunzip.3 \
		IO::Uncompress::Inflate.3 \
		IO::Uncompress::RawInflate.3 \
		IO::Uncompress::Unzip.3

.include <bsd.port.mk>
