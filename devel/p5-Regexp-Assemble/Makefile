# New ports collection makefile for:	devel/p5-Regexp-Assemble
# Date created:				3 March 2005
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Assemble
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Regexp
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Assemble multiple Regular Expressions into one RE

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Regexp::Assemble.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e "s/open my/open/;s/.fh/FH/g;s/'<',/'<'./" ${WRKSRC}/Assemble.pm
.endif

.include <bsd.port.post.mk>
