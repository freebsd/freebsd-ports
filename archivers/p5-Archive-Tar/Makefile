# New ports collection makefile for:	p5-Archive-Tar
# Date created:				Nov 14 2000
# Whom:	      				Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	Archive-Tar
PORTVERSION=	1.46
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl module for creation and manipulation of tar files

RUN_DEPENDS=	p5-IO-Compress-Bzip2>=2.012:${PORTSDIR}/archivers/p5-IO-Compress-Bzip2 \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

PERL_CONFIGURE=	YES

MAN1=		ptardiff.1 ptar.1
MAN3=		Archive::Tar.3 Archive::Tar::File.3

OPTIONS=	TEXT_DIFF "Text::Diff support for ptardiff" off

.include <bsd.port.pre.mk>

.if defined(WITH_TEXT_DIFF)
RUN_DEPENDS+=	${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
.endif

.if ${PERL_LEVEL} < 500904
RUN_DEPENDS+=	p5-Package-Constants>=0:${PORTSDIR}/devel/p5-Package-Constants
.endif

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib
.endif

.include <bsd.port.post.mk>
