# New ports collection makefile for:	databases/p5-Class-DBI-LazyInflate
# Date created:				05 February 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-LazyInflate
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Defer inflating of columns until they are used

BUILD_DEPENDS=	p5-Data-Lazy>=0:${PORTSDIR}/devel/p5-Data-Lazy \
		p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::LazyInflate.3

.include <bsd.port.mk>
