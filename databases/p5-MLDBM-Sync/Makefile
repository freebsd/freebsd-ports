# New ports collection makefile for:    p5-MLDBM-Sync
# Date created:                         May 29th, 2002
# Whom:                                 erwin@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	MLDBM-Sync
PORTVERSION=	0.30
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MLDBM::Sync - safe concurrent access to MLDBM databases

BUILD_DEPENDS=	${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MLDBM::Sync.3

.include <bsd.port.mk>
