# New ports collection makefile for:	p5-DBM-Deep
# Date created:		09 August 2004
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	DBM-Deep
PORTVERSION=	1.0014
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A pure perl persistent multi-level hash/array DBM

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/FileHandle/Fmode.pm:${PORTSDIR}/devel/p5-FileHandle-Fmode
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		DBM::Deep.3 DBM::Deep::Cookbook.3 DBM::Deep::Internals.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
