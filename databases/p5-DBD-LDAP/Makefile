# New ports collection makefile for:	DBD::LDAP
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	DBD-LDAP
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI interface for accessing LDAP servers

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBD::LDAP.3

.include <bsd.port.mk>
