# New ports collection makefile for:	p5-DBM-Deep
# Date created:		09 August 2004
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	DBM-Deep
PORTVERSION=	1.0024
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A pure perl persistent multi-level hash/array DBM

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/FileHandle/Fmode.pm:${PORTSDIR}/devel/p5-FileHandle-Fmode
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.14:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-IO-stringy>=0.01:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS+=	p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS+=	p5-Test-Warn>=0.08:${PORTSDIR}/devel/p5-Test-Warn
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		DBM::Deep.3 DBM::Deep::Cookbook.3 DBM::Deep::Internals.3 \
		DBM::Deep::Iterator::File::BucketList.3 \
		DBM::Deep::Iterator.3 DBM::Deep::Storage::File.3 \
		DBM::Deep::Engine.3 DBM::Deep::Storage.3 \
		DBM::Deep::Iterator::File::Index.3 DBM::Deep::Null.3 \
		DBM::Deep::Engine::File.3 DBM::Deep::Sector::File.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
