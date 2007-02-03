# New ports collection makefile for:	p5-POE-Filter-Bzip2
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-Bzip2
PORTVERSION=	1.5.0
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::Bzip2

RUN_DEPENDS=	p5-Compress-Bzip2>=2.08:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-POE>=0.3501:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::Bzip2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601	# Inherited from archivers/p5-Compress-Bzip2
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
