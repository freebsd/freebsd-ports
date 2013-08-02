# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forks
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SOAP/RYBSKEJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Drop-in replacement for Perl threads using fork()

BUILD_DEPENDS=	p5-Acme-Damn>=0:${PORTSDIR}/devel/p5-Acme-Damn \
		p5-Attribute-Handlers>=0:${PORTSDIR}/devel/p5-Attribute-Handlers \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-List-MoreUtils>=:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Sys-SigAction>=0.11:${PORTSDIR}/devel/p5-Sys-SigAction
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		forks.3 forks::signals.3 \
		forks::shared.3 \
		forks::Devel::Symdump.3 \
		threads::shared::array.3 \
		threads::shared::handle.3 \
		threads::shared::hash.3 \
		threads::shared::scalar.3

.include <bsd.port.mk>
