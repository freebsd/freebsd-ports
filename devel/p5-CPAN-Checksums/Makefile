# New ports collection makefile for:	p5-CPAN-Checksums
# Date created:				September 21st 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Checksums
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl module to write a CHECKSUMS file for a directory as on CPAN

BUILD_DEPENDS=	${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare
RUN_DEPENDS=	${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare

PERL_CONFIGURE=	YES

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-IO-Compress \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-IO-Compress \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA
.endif

MAN3=		CPAN::Checksums.3

.include <bsd.port.post.mk>
