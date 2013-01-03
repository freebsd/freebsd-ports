# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	Devel-NYTProf
PORTVERSION=	4.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Powerful feature-rich Perl source code profiler

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	nytprofhtml.1 \
	nytprofcsv.1 \
	nytprofcg.1 \
	nytprofmerge.1

MAN3=	Devel::MemoryProfiling.3 \
	Devel::NYTProf.3 \
	Devel::NYTProf::Apache.3 \
	Devel::NYTProf::Core.3 \
	Devel::NYTProf::Data.3 \
	Devel::NYTProf::FileInfo.3 \
	Devel::NYTProf::ReadStream.3 \
	Devel::NYTProf::Run.3 \
	Devel::NYTProf::Util.3

.include <bsd.port.mk>
