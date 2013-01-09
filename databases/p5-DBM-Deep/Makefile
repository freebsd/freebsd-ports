# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	DBM-Deep
PORTVERSION=	2.0008
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	A pure perl persistent multi-level hash/array DBM

BUILD_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-FileHandle-Fmode>=0:${PORTSDIR}/devel/p5-FileHandle-Fmode
RUN_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-FileHandle-Fmode>=0:${PORTSDIR}/devel/p5-FileHandle-Fmode

TEST_DEPENDS=	p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>=0.08:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		DBM::Deep.3 DBM::Deep::Cookbook.3 DBM::Deep::Internals.3 \
		DBM::Deep::Iterator::File::BucketList.3 \
		DBM::Deep::Iterator.3 DBM::Deep::Storage::File.3 \
		DBM::Deep::Engine.3 DBM::Deep::Storage.3 \
		DBM::Deep::Iterator::File::Index.3 DBM::Deep::Null.3 \
		DBM::Deep::Engine::File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
