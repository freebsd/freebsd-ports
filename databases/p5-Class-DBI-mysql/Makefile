# New ports collection makefile for:	p5-Class-DBI-mysql
# Date created:		14 August 2003
# Whom:	      		andrew@scoop.co.nz
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-mysql
PORTVERSION=	0.23
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew@scoop.co.nz
COMMENT=	Extensions to Class::DBI for MySQL

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::mysql.3

.include <bsd.port.mk>
