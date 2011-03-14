# New ports collection makefile for:	p5-Dancer-Plugin-Database
# Date created:				Dec 23, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-Database
PORTVERSION=	1.21
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Easy database connections for Dancer applications

BUILD_DEPENDS=	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Dancer::Plugin::Database.3 \
		Dancer::Plugin::Database::Handle.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
