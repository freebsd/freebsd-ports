# New ports collection makefile for:	InlineX::C2XS
# Date created:		3 Oct 2006
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	InlineX-C2XS
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SI/SISYPHUS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module to create an XS file from an Inline C file

BUILD_DEPENDS=	${SITE_PERL}/Inline/C.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		InlineX::C2XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
do-patch:
	${PERL} -pi -e 's/^our (\W\w+);/use vars q($$1);/o;' \
	    -e 's/^our\s+(\W\w+)(?!;)/use vars q($$1); $$1/o;' \
	    -e 'undef $$_ if /^\s*(no|use) warnings/o;' \
	    ${WRKSRC}/C2XS.pm
.endif

.include <bsd.port.post.mk>
