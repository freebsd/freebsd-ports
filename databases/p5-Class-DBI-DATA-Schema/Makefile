# New ports collection makefile for:	databases/p5-Class-DBI-DATA-Schema
# Date created:				24 October 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-DATA-Schema
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Execute Class::DBI SQL from DATA sections

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::DATA::Schema.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
post-patch:
	${PERL} -pi -e '$$_ = "" if /use warnings/;' \
		    -e '$$_ = "" if /ABSTRACT_FROM/;' \
		    -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/Makefile.PL \
		${WRKSRC}/lib/Class/DBI/DATA/Schema.pm
.endif
.include <bsd.port.post.mk>
