# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Perl-Version
PORTVERSION=	1.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse and manipulate Perl version strings

RUN_DEPENDS=	p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		perl-reversion.1
MAN3=		Perl::Version.3

NO_STAGE=	yes
.include <bsd.port.mk>
