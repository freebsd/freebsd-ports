# New ports collection makefile for:	databases/p5-Search-InvertedIndex
# Date created:				Oct 23 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Search-InvertedIndex
PORTVERSION=	1.14
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A manager for inverted index maps

BUILD_DEPENDS=	${SITE_PERL}/Class/NamedParms.pm:${PORTSDIR}/devel/p5-Class-NamedParms \
		${SITE_PERL}/Class/ParmList.pm:${PORTSDIR}/devel/p5-Class-ParmList \
		${SITE_PERL}/Tie/DB_File/SplitHash.pm:${PORTSDIR}/devel/p5-Tie-DB_File-SplitHash \
		${SITE_PERL}/Tie/FileLRUCache.pm:${PORTSDIR}/devel/p5-Tie-FileLRUCache
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Search::InvertedIndex.3 \
		Search::InvertedIndex::AutoLoader.3 \
		Search::InvertedIndex::DB::DB_File_SplitHash.3 \
		Search::InvertedIndex::DB::Mysql.3 \
		Search::InvertedIndex::Query.3 \
		Search::InvertedIndex::Update.3 \
		Search::InvertedIndex::Query::Leaf.3 \
		Search::InvertedIndex::Result.3

.include <bsd.port.mk>
