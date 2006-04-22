# New ports collection makefile for:	String-Random
# Date created:				Mon Jan  1 11:19:27 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	String-Random
PORTVERSION=	0.21
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to generate "random" strings

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes

MAN3=		String::Random.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_ = "" if m{use warnings};' ${WRKSRC}/lib/String/Random.pm \
		${WRKSRC}/Build.PL ${WRKSRC}/t/*.t
.endif

.include <bsd.port.post.mk>
