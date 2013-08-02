# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bio-Das-Lite
PORTVERSION=	2.11
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the DAS (HTTP+XML) Protocol

BUILD_DEPENDS=	p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-WWW-Curl>=4.07:${PORTSDIR}/www/p5-WWW-Curl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>0.8:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Bio::Das::Lite.3

.include <bsd.port.mk>
