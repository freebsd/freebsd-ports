# New ports collection makefile for:	p5-Bio-GFF3
# Date created:				22 Apr, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-GFF3
PORTVERSION=	1.3
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast low-level functions for parsing and formatting GFF3

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

PERL_CONFIGURE=	YES

MAN1=		gff3_from_fasta.1
MAN3=		Bio::GFF3::LowLevel.3 \
		Bio::GFF3::LowLevel::Parser.3 \
		Bio::GFF3::LowLevel::Parser::1_0_backcompat.3 \
		Bio::GFF3::Transform::FromFasta.3

.include <bsd.port.mk>
