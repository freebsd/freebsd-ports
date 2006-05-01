# New ports collection makefile for:    p5-Test-Deep
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Deep
PORTVERSION=	0.095
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Test data structures for differences deeply

BUILD_DEPENDS=	${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::Deep.3

post-patch:
	@${PERL} -i -pe 'm/INSTALLDIRS\s+=>/ and $$_ = ""' \
			${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or above
.endif

.include <bsd.port.post.mk>
