# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-JFDI
PORTVERSION=	0.065
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROKR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst::Plugin::ConfigLoader-style layer over Config::Any

BUILD_DEPENDS=	p5-Carp-Clan-Share>=0:devel/p5-Carp-Clan-Share \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Clone>=0:devel/p5-Clone \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Data-Visitor>=0.24:devel/p5-Data-Visitor
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -i '' '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
