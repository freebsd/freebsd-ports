# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Data-ClearSilver-HDF
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Convert from Perl Data Structure to ClearSilver HDF

BUILD_DEPENDS=	p5-ClearSilver>=0:www/p5-ClearSilver \
		p5-Data-Structure-Util>=0:devel/p5-Data-Structure-Util \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
