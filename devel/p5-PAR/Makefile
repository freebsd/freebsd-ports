# New ports collection makefile for:	devel/p5-PAR
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PAR
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AU/AUTRIJUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Perl Archive Toolkit

BUILD_DEPENDS=	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Module/ScanDeps/DataFeed.pm:${PORTSDIR}/devel/p5-Module-ScanDeps \
		${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature \
		${SITE_PERL}/PAR/Dist.pm:${PORTSDIR}/devel/p5-PAR-Dist \
		${SITE_PERL}/B/Deobfuscate.pm:${PORTSDIR}/devel/p5-B-Deobfuscate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		par.pl.1 parl.1 pp.1 tkpp.1
MAN3=		App::Packer::PAR.3 PAR.3 \
		PAR::Packer.3 PAR::FAQ.3 PAR::Filter.3 \
		PAR::Filter::Bleach.3 PAR::Filter::Bytecode.3 \
		PAR::Filter::Obfuscate.3 PAR::Filter::PatchContent.3 \
		PAR::Filter::PodStrip.3 PAR::Heavy.3 PAR::Tutorial.3

CONFLICTS=	nss-*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.if ${PERL_LEVEL} < 500601
IGNORE=		p5-PAR only supports the ports versions of Perl.
IGNORE+=If you have installed a Perl port, and are getting this message,
IGNORE+=please make sure you have given the command \'use.perl port\'
.endif # ${PERL_LEVEL} < 500601

.include <bsd.port.post.mk>
