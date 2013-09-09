# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Data-ClearSilver-HDF
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Convert from Perl Data Structure to ClearSilver HDF

BUILD_DEPENDS=	p5-ClearSilver>=0:${PORTSDIR}/www/p5-ClearSilver \
		p5-Data-Structure-Util>=0:${PORTSDIR}/devel/p5-Data-Structure-Util \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	cspage.1

MAN3=	Data::ClearSilver::HDF.3

.include <bsd.port.mk>
