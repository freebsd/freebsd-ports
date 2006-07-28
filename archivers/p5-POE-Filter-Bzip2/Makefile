# New ports collection makefile for:	p5-POE-Filter-Bzip2
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-Bzip2
PORTVERSION=	1.2
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A POE filter wrapped around Compress::Bzip2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::Bzip2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601	# Inherited from archivers/p5-Compress-Bzip2
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
