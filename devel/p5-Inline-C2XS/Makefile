# New ports collection makefile for:	Inline::C2XS
# Date created:		3 Oct 2006
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Inline-C2XS
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Inline
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module to create an XS file from an Inline C file

BUILD_DEPENDS=	${SITE_PERL}/Inline/C.pm:${PORTSDIR}/devel/p5-Inline \
    		${SITE_PERL}/Inline/CPP.pm:${PORTSDIR}/devel/p5-Inline-CPP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Inline::C2XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
do-patch:
	${PERL} -pi -e 's/^our (\W\w+);/use vars q($$1);/o;' \
	    -e 's/^our\s+(\W\w+)(?!;)/use vars q($$1); $$1/o;' \
	    -e 'undef $$_ if /^\s*(no|use) warnings/o;' \
	    ${WRKSRC}/C2XS.pm
.endif

.include <bsd.port.post.mk>
