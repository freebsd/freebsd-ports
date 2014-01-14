# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Class-Most
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OVID
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Test Classes the easy way

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-Class>=0.38:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Most>=0.31:${PORTSDIR}/devel/p5-Test-Most
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

PLIST_FILES=	%%SITE_PERL%%/Test/Class/Most.pm \
		%%PERL5_MAN3%%/Test::Class::Most.3.gz
PLIST_DIRSTRY=	%%SITE_PERL%%/Test/Class %%SITE_PERL%%/Test

.include <bsd.port.mk>
