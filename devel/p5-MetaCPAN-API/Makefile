# New ports collection makefile for:	devel/p5-MetaCPAN-API
# Date created:				14 November 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MetaCPAN-API
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A comprehensive, DWIM-featured API to MetaCPAN

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-HTTP-Tiny>=0:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-TinyMocker>=0:${PORTSDIR}/devel/p5-Test-TinyMocker

PERL_MODBUILD=	yes

MAN3=		MetaCPAN::API.3 MetaCPAN::API::Author.3 \
		MetaCPAN::API::Module.3 \
		MetaCPAN::API::POD.3 \
		MetaCPAN::API::Release.3 \
		MetaCPAN::API::Source.3

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${PERL5} ${PL_BUILD} test
.endif

.include <bsd.port.mk>
