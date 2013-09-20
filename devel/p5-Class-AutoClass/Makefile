# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Class-AutoClass
PORTVERSION=	1.55
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create get and set methods and simplify object initialization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Hash-AutoHash-Args>=1.10:${PORTSDIR}/devel/p5-Hash-AutoHash-Args
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=2.1:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-Deep>=0.098:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	modbuild
USES=		perl5

MAN3=		Class::AutoClass.3

NO_STAGE=	yes
.include <bsd.port.mk>
