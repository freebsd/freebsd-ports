# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Class-AutoClass
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	autoclass_v${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically define simple get and set methods in an inheritance structure

RUN_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/AutoClass

MAN3=		Class::AutoClass::Root.3 Class::AutoClass.3 Class::AutoClass::Args.3

.include <bsd.port.mk>
