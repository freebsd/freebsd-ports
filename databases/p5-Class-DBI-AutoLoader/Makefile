# ex:ts=8
# Ports collection makefile for:	Class::DBI::AutoLoader
# Date created:			Sep 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-AutoLoader
PORTVERSION=	0.12
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates Class::DBI subclasses dynamically

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Class/DBI/BaseDSN.pm:${PORTSDIR}/databases/p5-Class-DBI-BaseDSN
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::AutoLoader.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use warnings/;' \
       		-e 's/^our (\S+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/AutoLoader.pm
.endif

.include <bsd.port.post.mk>
