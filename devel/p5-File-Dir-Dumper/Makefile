# New ports collection makefile for:	p5-File-Dir-Dumper
# Date created:				November 18th 2008
# Whom:                                 Anatoliy Dmytriyev <tolid@tolid.eu.org>
#
# $FreeBSD$
#

PORTNAME=	File-Dir-Dumper
PORTVERSION=	0.0.8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	tolid@tolid.eu.org
COMMENT=	Perl5 module to dump directory structures meta-data

BUILD_DEPENDS=	p5-File-Find-Object>0:${PORTSDIR}/devel/p5-File-Find-Object \
		p5-IO-String>0:${PORTSDIR}/devel/p5-IO-String \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Devel-CheckOS>0:${PORTSDIR}/devel/p5-Devel-CheckOS
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		dir-dump.1
MAN3=		File::Dir::Dumper.3 File::Dir::Dumper::App.3 File::Dir::Dumper::Base.3 File::Dir::Dumper::Scanner.3 \
		File::Dir::Dumper::Stream::JSON::Reader.3 File::Dir::Dumper::Stream::JSON::Writer.3

.include <bsd.port.mk>
