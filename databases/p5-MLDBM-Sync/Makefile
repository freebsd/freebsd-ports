# New ports collection makefile for:    p5-MLDBM-Sync
# Date created:                         May 29th, 2002
# Whom:                                 erwin@lansing.dk
#
# $FreeBSD$
#

PORTNAME=	MLDBM-Sync
PORTVERSION=	0.30
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MLDBM
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MLDBM::Sync.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
