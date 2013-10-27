# $FreeBSD$

PORTNAME=	DBIx-Class-Migration
PORTVERSION=	0.043
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to make migrating your DBIx::Class databases easier

RUN_DEPENDS=	\
	p5-Class-Load>0:${PORTSDIR}/devel/p5-Class-Load \
	p5-Config-MySQL>=0.02:${PORTSDIR}/devel/p5-Config-MySQL \
	p5-DBD-SQLite>=1.35:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Class-DeploymentHandler>=0.002100:${PORTSDIR}/databases/p5-DBIx-Class-DeploymentHandler \
	p5-DBIx-Class-Fixtures>=1.001016:${PORTSDIR}/databases/p5-DBIx-Class-Fixtures \
	p5-DBIx-Class-Schema-Loader>=0.07017:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Devel-PartialDump>0:${PORTSDIR}/devel/p5-Devel-PartialDump \
	p5-File-ShareDir-ProjectDistDir>=0.3.1:${PORTSDIR}/devel/p5-File-ShareDir-ProjectDistDir \
	p5-JSON-XS>=2.32:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Attribute-ENV>=0.02:${PORTSDIR}/devel/p5-MooseX-Attribute-ENV \
	p5-MooseX-Getopt>=0.45:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-Traits-Pluggable>0:${PORTSDIR}/devel/p5-MooseX-Traits-Pluggable \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-LoadableClass>0:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
	p5-Pod-Parser>0:${PORTSDIR}/textproc/p5-Pod-Parser \
	p5-SQL-Translator>=0.11010:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-Text-Brew>0:${PORTSDIR}/textproc/p5-Text-Brew
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Most>0:${PORTSDIR}/devel/p5-Test-Most \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-Trap>0:${PORTSDIR}/devel/p5-Test-Trap \
	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny

USES=	perl5
USE_PERL5=	configure

post-patch:
	${FIND} ${WRKSRC} -name .DS_Store -delete

.include <bsd.port.mk>
