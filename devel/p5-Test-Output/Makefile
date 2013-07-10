# Created by:	Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Test-Output
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Utilities to test STDOUT and STDERR messages

RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Tester>=0.10.7:${PORTSDIR}/devel/p5-Test-Tester

PERL_CONFIGURE=	yes

MAN3=		Test::Output.3

post-patch:
	@${REINPLACE_CMD} -e '/File::Temp/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
