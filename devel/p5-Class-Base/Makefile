# New ports collection makefile for:	p5-Class-Base
# Date created:				Nov 23 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-Base
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Useful base class for deriving other modules

PERL_CONFIGURE=	yes

MAN3=		Class::Base.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -i -pe 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/Class/Base.pm
.endif

.include <bsd.port.post.mk>
