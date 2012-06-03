# New ports collection makefile for:	DBD::LDAP
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	DBD-LDAP
PORTVERSION=	0.20
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI interface for accessing LDAP servers

BUILD_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBD::LDAP.3

.include <bsd.port.mk>
