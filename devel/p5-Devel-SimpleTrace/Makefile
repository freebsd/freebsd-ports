# Created by: estith
# $FreeBSD$

PORTNAME=	Devel-SimpleTrace
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Perl module for better stack traces on interpreter-generated warn/die

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Devel::SimpleTrace.3

NO_STAGE=	yes
.include <bsd.port.mk>
