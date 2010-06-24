# New ports collection makefile for:	p5-IO-Compress-Zlib
# Date created:				3 December 2006
# Whom:	      				Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Zlib
PORTVERSION=	2.015
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 interface for reading and writing of (g)zip files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Raw/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		${SITE_PERL}/IO/Compress/Base.pm:${PORTSDIR}/archivers/p5-IO-Compress-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		IO::Uncompress::RawInflate.3 IO::Uncompress::Unzip.3 \
		IO::Uncompress::Inflate.3 IO::Compress::Deflate.3 \
		IO::Compress::Zip.3 IO::Uncompress::Gunzip.3 \
		IO::Compress::RawDeflate.3 IO::Uncompress::AnyInflate.3 \
		IO::Compress::Gzip.3

post-patch:
	@${REINPLACE_CMD} -e 's/5.009/5.666/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
