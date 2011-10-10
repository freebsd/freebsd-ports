# New ports collection makefile for:	p5-Bio-GFF3
# Date created:				22 Apr, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-GFF3
PORTVERSION=	0.7
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast, low-level functions for parsing and formatting GFF3

BUILD_DEPENDS=	p5-File-ReadBackwards>=0:${PORTSDIR}/devel/p5-File-ReadBackwards \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		gff3_insert_sync_directives.1 \
		gff3_from_fasta.1
MAN3=		Bio::GFF3::Transform::SyncDirectives.3 \
		Bio::GFF3::LowLevel.3 \
		Bio::GFF3::Transform::FromFasta.3

.include <bsd.port.mk>
