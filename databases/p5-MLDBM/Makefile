# New ports collection makefile for:    p5-MLDBM
# Date created:                         December 3 1997
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	MLDBM
PORTVERSION=	2.01
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MLDBM
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Store multi-level hash structure in single level tied hash

BUILD_DEPENDS=	${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MLDBM.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
