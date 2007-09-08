# New ports collection makefile for:	p5-Class-DBI-Loader-Relationship
# Date created:				Apr 4 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-DBI-Loader-Relationship
PORTVERSION=	1.3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/C/CH/CHUNZI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easier relationship specification in CDBI::L

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI/Loader.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		${SITE_PERL}/Lingua/EN/Inflect/Number.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Loader::Relationship.3

.include <bsd.port.mk>
