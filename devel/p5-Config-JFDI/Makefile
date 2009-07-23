# New ports collection makefile for:	devel/p5-Config-JFDI
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-JFDI
PORTVERSION=	0.063
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A Catalyst::Plugin::ConfigLoader-style layer over Config::Any

BUILD_DEPENDS=	\
	p5-Hash-Merge-Simple>=0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
	p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Config::JFDI.3

post-extract:
	@${PERL} -i -ne 'print unless /\.swp$$/' ${WRKSRC}/MANIFEST
	@${PERL} -i.bak -ne 'print unless m,^Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
