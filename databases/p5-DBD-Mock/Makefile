# New ports collection makefile for:	DBD::Mock
# Date created:				02 December 2005
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	DBD-Mock
PORTVERSION=	1.39
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Simple mock DBD implementation used for testing

BUILD_DEPENDS=	p5-DBI>=1.3:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.6+

MAN3=		DBD::Mock.3

.include <bsd.port.mk>
