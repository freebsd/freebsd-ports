# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	CPAN-Checksums
PORTVERSION=	2.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to write a CHECKSUMS file for a directory as on CPAN

BUILD_DEPENDS=	p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature
RUN_DEPENDS=	p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature
TEST_DEPENDS=	p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2

PERL_CONFIGURE=	YES

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
.endif

MAN3=		CPAN::Checksums.3

.include <bsd.port.post.mk>
