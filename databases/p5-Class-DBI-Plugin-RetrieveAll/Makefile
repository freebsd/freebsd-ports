# New ports collection makefile for:	p5-Class-DBI-Plugin-RetrieveAll
# Date created:				Apr 2 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-RetrieveAll
PORTVERSION=	1.01
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	More complex retrieve_all() for Class::DBI

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Plugin::RetrieveAll.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		    -e '$$_="" if /use warnings/;' \
		${WRKSRC}/lib/Class/DBI/Plugin/RetrieveAll.pm
.endif

.include <bsd.port.post.mk>
