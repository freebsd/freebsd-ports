# New ports collection makefile for:	p5-Class-DBI-AsForm
# Date created:				Apr 3 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-DBI-AsForm
PORTVERSION=	2.3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Produce HTML form elements for database columns

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Class/DBI/Plugin/Type.pm:${PORTSDIR}/databases/p5-Class-DBI-Plugin-Type
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::AsForm.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/500503-AsForm.pm
.endif

.include <bsd.port.post.mk>
