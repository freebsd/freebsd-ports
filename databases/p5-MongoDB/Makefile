# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MongoDB
PORTVERSION=	0.45
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KRISTINA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mongo Driver for Perl

LICENSE=	AL2

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean
RUN_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean

TEST_DEPENDS=	p5-Data-Types>=0:${PORTSDIR}/devel/p5-Data-Types \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

MAN3=		MongoDB.3 \
		MongoDB::BSON.3 \
		MongoDB::Code.3 \
		MongoDB::Collection.3 \
		MongoDB::Connection.3 \
		MongoDB::Cursor.3 \
		MongoDB::DataTypes.3 \
		MongoDB::Database.3 \
		MongoDB::Examples.3 \
		MongoDB::GridFS.3 \
		MongoDB::GridFS::File.3 \
		MongoDB::Indexing.3 \
		MongoDB::OID.3 \
		MongoDB::Timestamp.3 \
		MongoDB::Tutorial.3

.include <bsd.port.mk>
