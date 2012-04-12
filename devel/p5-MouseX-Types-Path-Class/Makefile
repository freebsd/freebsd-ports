# New ports collection makefile for:	p5-MouseX-Types-Path-Class
# Date created:		2009-04-22
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Types-Path-Class
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	A Path::Class type library for Mouse

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=0.39:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-Types>=0.02:${PORTSDIR}/devel/p5-MouseX-Types \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-MouseX-Getopt>=0.22:${PORTSDIR}/devel/p5-MouseX-Getopt
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-UseAllModules>0:${PORTSDIR}/devel/p5-Test-UseAllModules

PERL_CONFIGURE=	yes

MAN3=		MouseX::Types::Path::Class.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
