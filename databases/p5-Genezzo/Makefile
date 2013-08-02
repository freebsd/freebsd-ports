# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Genezzo
PORTVERSION=	0.72
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible database with SQL and DBI

RUN_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		gendba.pl.1 genexp.pl.1
MAN3=		Genezzo.3 Genezzo::Block::RDBArray.3 \
		Genezzo::BasicHelp.3 \
		Genezzo::Block::RDBlkA.3 Genezzo::Block::RDBlk_NN.3 \
		Genezzo::Block::RDBlock.3 Genezzo::Block::RowDir.3 \
		Genezzo::Block::Std.3 Genezzo::Block::Util.3 \
		Genezzo::BufCa::BCFile.3 Genezzo::BufCa::BufCa.3 \
		Genezzo::BufCa::BufCaElt.3 Genezzo::BufCa::DirtyScalar.3 \
		Genezzo::BufCa::PinScalar.3 Genezzo::Dict.3 \
		Genezzo::GenDBI.3 Genezzo::Havok.3 Genezzo::Havok::Basic.3 \
		Genezzo::Havok::DebugUtils.3 Genezzo::Havok::Examples.3 \
		Genezzo::Havok::OO_Examples.3 Genezzo::Havok::SQLScalar.3 \
    		Genezzo::Havok::SQLCompare.3 Genezzo::Havok::SysHelp.3 \
		Genezzo::Havok::SysHook.3 Genezzo::Havok::UserExtend.3 \
		Genezzo::Havok::UserFunctions.3 Genezzo::Havok::Utils.3 \
		Genezzo::Index::bt2.3 Genezzo::Index::bt3.3 \
		Genezzo::Index::btHash.3 \
		Genezzo::Parse::SQL.3 Genezzo::Parse::SQLGrammar.3 \
		Genezzo::Plan.3 Genezzo::Plan::MakeAlgebra.3 \
		Genezzo::Plan::QueryRewrite.3 Genezzo::Plan::TypeCheck.3 \
		Genezzo::PushHash::HPHRowBlk.3 Genezzo::PushHash::PHArray.3 \
		Genezzo::PushHash::PHFixed.3 Genezzo::PushHash::PHNoUpdate.3 \
		Genezzo::PushHash::PushHash.3 Genezzo::PushHash::hph.3 \
		Genezzo::RawIO.3 Genezzo::Row::RSBlock.3 \
		Genezzo::Row::RSDual.3 Genezzo::Row::RSExpr.3 \
		Genezzo::Row::RSFile.3 Genezzo::Row::RSIdx1.3 \
		Genezzo::Row::RSJoinA.3 Genezzo::Row::RSTab.3 \
		Genezzo::SpaceMan::SMExtent.3 Genezzo::SpaceMan::SMFile.3 \
		Genezzo::SpaceMan::SMHook.3 Genezzo::TSHash.3 \
		Genezzo::SpaceMan::SMFreeBlock.3 \
		Genezzo::Tablespace.3 Genezzo::TestSetup.3 \
		Genezzo::TestSQL.3 \
		Genezzo::Util.3 Genezzo::XEval.3 Genezzo::XEval::Prepare.3 \
		Genezzo::XEval::SQLAlter.3 Genezzo::gendba.3 Genezzo::genexp.3

.include <bsd.port.mk>
