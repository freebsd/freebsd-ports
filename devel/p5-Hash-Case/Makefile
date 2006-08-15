# New ports collection makefile for:	p5-Hash-Case
# Date created:		2006-08-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Hash-Case
PORTVERSION=	1.003
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Hash
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Base class for hashes with key-casing requirements

PERL_CONFIGURE=	yes

MAN3=		Hash::Case.3 Hash::Case::Lower.3 Hash::Case::Preserve.3 \
		Hash::Case::Upper.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\W\w+);/use vars q($$1);/o;' \
	    	-e 's/^our\s+(\W\w+)(?!;)/use vars q($$1); $$1/o;' \
		-e 'undef $$_ if /^\s*(no|use) warnings/o;' \
		${WRKSRC}/lib/Hash/Case.pm
.endif

.include <bsd.port.post.mk>
